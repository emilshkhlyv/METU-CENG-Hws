#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <unistd.h> 
#include "message.h"
#include "logging.c"
#include "logging.h"
#include <sys/wait.h>
#include <sys/time.h>
#define PIPE(fd) socketpair(AF_UNIX, SOCK_STREAM, PF_UNIX, fd)

typedef struct bido_info{
    char **arguments;
    char *path;
    int  bid_argument;
} bid;

int main(){
    int starting_bid, min_inc, N_of_bidders, highest_bid, highest_bidder;
    long min_delay = __LONG_MAX__;
    scanf("%d %d %d\n", &starting_bid, &min_inc, &N_of_bidders);
    highest_bid = starting_bid;
    int i, j, k;
    bid* bidders = (bid*)malloc(sizeof(bid)*N_of_bidders);
    //getting Bidders' info
    for(i = 0; i < N_of_bidders; ++i){
        bidders[i].path = (char *)malloc(sizeof(char)*300);
        scanf("%s", bidders[i].path);
        scanf("%d", &bidders[i].bid_argument);
        bidders[i].arguments = (char**)malloc(sizeof(char*)*(bidders[i].bid_argument+2));
        bidders[i].arguments[0] = bidders[i].path;
        for(j = 1; j < bidders[i].bid_argument+1; ++j){
            bidders[i].arguments[j] = (char *)malloc(sizeof(char)*20);
            scanf("%s", bidders[i].arguments[j]);
        }
        bidders[i].arguments[j] = NULL;
    }
    
    int fd[N_of_bidders][2];
    pid_t pid[N_of_bidders];
    int status[N_of_bidders];

    //pipes, forks and execs
    for(i = 0; i <  N_of_bidders; ++i){
        PIPE(fd[i]);
        if((pid[i] = fork()) != 0){
            close(fd[i][1]);
        }
        else{
            close(fd[i][0]);
            dup2(fd[i][1], 0);
            dup2(fd[i][1], 1);
            close(fd[i][1]);
            execvp(bidders[i].path, bidders[i].arguments);
        }
    }    

    fd_set readset;
    int m = 0, flag = 1;
    int open[N_of_bidders];

    //open fds and find nfds
    for(i = 0; i < N_of_bidders; ++i){
        open[i] = 1;
        m = ((fd[i][0] > m) ? fd[i][0] : m);
    }
    ++m;

    cm  client_message_local;
    cmp client_message_parameters_local;
    cei connection_established_info_local;
    bi  bid_info_local;
    wi  winner_info_local;
    smp server_message_parameters_local;
    sm  server_message_local;
    ii  input_info_local;
    oi  output_info_local;
    
    long* delay = (long*)calloc(N_of_bidders, sizeof(long));

    struct  timeval timeout;
    timeout.tv_usec = 0;
    timeout.tv_sec = 0;
    int r;
    
    while(flag){
        FD_ZERO(&readset);
        for(j = 0; j < N_of_bidders; ++j){
            if(open[j]) {
                FD_SET(fd[j][0], &readset);
                if(delay[j] != 0){
                    min_delay = (delay[j] < min_delay)? delay[j] : min_delay;
                    timeout.tv_usec = min_delay*1000;
                }
            }
        }
        select(m, &readset, NULL, NULL, &timeout);
        for(j = 0; j < N_of_bidders; ++j){
            if(FD_ISSET(fd[j][0], &readset)){
                r  = read(fd[j][0], &client_message_local, sizeof(cm));
                if(r == 0){
                    open[j] = 0;
                }
                else
                {
                    switch (client_message_local.message_id)
                    {
                        case 1:{
                            input_info_local.pid  = pid[j];
                            input_info_local.type = client_message_local.message_id;
                            input_info_local.info = client_message_local.params;
                            delay[j] = client_message_local.params.delay;
                            print_input(&input_info_local, j);
                            
                            server_message_parameters_local.start_info.client_id            = j;
                            server_message_parameters_local.start_info.current_bid          = highest_bid;
                            server_message_parameters_local.start_info.minimum_increment    = min_inc;
                            server_message_parameters_local.start_info.starting_bid         = starting_bid;

                            output_info_local.type  = SERVER_CONNECTION_ESTABLISHED;
                            output_info_local.pid   = pid[j];
                            output_info_local.info  = server_message_parameters_local;
                            print_output(&output_info_local, j);

                            server_message_local.message_id = SERVER_CONNECTION_ESTABLISHED;
                            server_message_local.params     = server_message_parameters_local;
                            write(fd[j][0], &server_message_local, sizeof(sm));
                            break;
                        }
                        case 2:{
                            input_info_local.pid  = pid[j];
                            input_info_local.type = client_message_local.message_id;
                            input_info_local.info = client_message_local.params;
                            print_input(&input_info_local, j);    

                            if(input_info_local.info.bid < starting_bid){
                                bid_info_local.result       = BID_LOWER_THAN_STARTING_BID;
                                bid_info_local.current_bid  = highest_bid;
                            }
                            else if(input_info_local.info.bid < highest_bid){
                                bid_info_local.result       = BID_LOWER_THAN_CURRENT;
                                bid_info_local.current_bid  = highest_bid;
                            } 
                            else if(abs(input_info_local.info.bid - highest_bid) < min_inc){
                                bid_info_local.result       = BID_INCREMENT_LOWER_THAN_MINIMUM;
                                bid_info_local.current_bid  = highest_bid;
                            }
                            else{
                                bid_info_local.result       = BID_ACCEPTED;
                                highest_bid                 = input_info_local.info.bid;
                                highest_bidder              = j;
                                bid_info_local.current_bid  = highest_bid;
                            }      
                            output_info_local.type              = SERVER_BID_RESULT;
                            output_info_local.pid               = pid[j];
                            output_info_local.info.result_info  = bid_info_local;      
                            print_output(&output_info_local, j);      

                            server_message_local.message_id                     = SERVER_BID_RESULT;
                            server_message_local.params.result_info.current_bid = highest_bid;
                            server_message_local.params.result_info             = bid_info_local;
                            write(fd[j][0], &server_message_local, sizeof(sm));
                            break;
                        }
                        case 3:{
                            input_info_local.type   = client_message_local.message_id;
                            input_info_local.pid    = pid[j];
                            input_info_local.info   = client_message_local.params;
                            status[j] = client_message_local.params.status;
                            open[j] = 0;
                            print_input(&input_info_local, j);
                            break;
                        }
                    }
                }
            }
        }
        for(i = 0, flag = 0; i < N_of_bidders; ++i){
            flag = (flag || open[i]);
        }  
    }
    print_server_finished(highest_bidder, highest_bid);

    server_message_parameters_local.winner_info.winner_id   = highest_bidder;
    server_message_parameters_local.winner_info.winning_bid = highest_bid;
    server_message_local.message_id                         = SERVER_AUCTION_FINISHED;
    server_message_local.params                             = server_message_parameters_local;

    output_info_local.type  = SERVER_AUCTION_FINISHED;
    output_info_local.info  = server_message_parameters_local;
    for(j = 0; j < N_of_bidders; ++j){
        output_info_local.pid   = pid[j];
        print_output(&output_info_local, j);
        write(fd[j][0], &server_message_local, sizeof(sm));
    }
    
    for(j = 0; j < N_of_bidders; ++j){
        close(fd[j][0]);
        close(fd[j][1]);
    }

    int status_local, status_match_local;
    for(j = 0; j < N_of_bidders; ++j){
        wait(&status_local);
        status_match_local = (WEXITSTATUS(status_local) == status[j]);
        print_client_finished(j, status[j], status_match_local);
    }
    
    for(i = 0; i < N_of_bidders; ++i){
        free(bidders[i].path);
        for(j = 1; j < bidders[i].bid_argument+2; ++j){
            free(bidders[i].arguments[j]);
        }
        free(bidders[i].arguments);
    }
    free(bidders);
    free(delay);
    return 0;
}
