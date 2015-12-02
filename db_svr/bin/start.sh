#!/bin/sh

PROGRAM="db_svr"
CMD="./db_svr"
PS_RECORD=`ps -ef | grep -v grep | grep "\./${PROGRAM}"`

if [ "${PS_RECORD}" != "" ]; then
    echo "# ${PROGRAM} is RUNNING"
    echo "${PS_RECORD}"
    exit 0
else
    #export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:../../libs/lib/
    #ulimit -n 100000
    ulimit -s unlimited
    ulimit -c unlimited
    echo "`date` start db_svr" >> start.log
    ${CMD} 1>>start.log &

    sleep 1

    PS_CHECK=`ps -ef | grep -v grep | grep "\./${PROGRAM}"`
    if [ "${PS_CHECK}" = "" ]; then
        echo "# starting ${PROGRAM} FAILED"
        exit -1
    else
        echo "# ${PROGRAM} started"
        echo "${PS_CHECK}"
        exit 0
    fi
fi
