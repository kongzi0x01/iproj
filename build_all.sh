#!/bin/sh 
echo "************build service_svr**************"
cd service_svr/build/
sh build.sh

echo "************build db_svr**************"
cd ../../db_svr/build/
sh build.sh
