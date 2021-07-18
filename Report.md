Report to XV6 Schedulers:

The given XV6 schedulers are tested by benchmark.c which creates multiple processess with respective i/o and cpu at a time to complete.

Results of total exceution time by benchmark with no changes in i/o and cpu times:

Calulated by uptime function :

    RR: 2010    FCFS:2317   PBS:2007    MLFQ:2008

    Analysis :
            Since it is multiprocessing MLFQ , RR and PBS are effective so RR~=PBS~=MLFQ. But FCFS is non-preemptive ,so the running time is high.
    Here MLFQ and RR are more effective in both i/o and cpu time calulated by the uptime.


Results of total exceution time by benchmark with only cpu calulation:

Calulated by uptime function :

    RR:2114    FCFS:2383   PBS:2177    MLFQ:2446

    Analysis :
            Since only cpu time plays role RR is more effective to reduce wait time and compute multiprocesses quickly.