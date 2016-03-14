#!/bin/sh 
echo "************build service_svr**************"
cd service_svr/build/
sh clean_build.sh

echo "************build db_svr**************"
cd ../../db_svr/build/
sh clean_build.sh

echo "************build http_svr**************"
cd ../../http_svr/build/
sh clean_build.sh
