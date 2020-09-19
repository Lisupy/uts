#!/bin/bash
docker-compose -f ./dockerfile/docker-compose.yml up -d
docker exec -it uts_env /bin/bash
docker-compose -f ./dockerfile/docker-compose.yml stop
