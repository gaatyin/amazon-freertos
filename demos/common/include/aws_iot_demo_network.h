/*
 * Amazon FreeRTOS
 * Copyright (C) 2017 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://aws.amazon.com/freertos
 * http://www.FreeRTOS.org
 */


/**
 * @file aws_iot_mqtt_demo_network.h
 * @brief Containis functions for handling network connections for MQTT demo
 */
#ifndef AWS_IOT_DEMO_NETWORK_H_
#define AWS_IOT_DEMO_NETWORK_H_



#ifdef AWS_IOT_CONFIG_FILE
    #include AWS_IOT_CONFIG_FILE
#endif

#include "aws_iot_mqtt.h"

typedef void* AwsIotDemoNetworkConnection_t;

typedef void ( *NetworkDisconnectedCallback_t ) ( AwsIotDemoNetworkConnection_t );


void ulCreateNetworkConnectionWithRetry(
        uint32_t ulConnIntervalSec,
        uint32_t ulConnRetryLimit,
        AwsIotMqttNetIf_t* pxNetworkInterface,
        AwsIotMqttConnection_t* pxMqttConnection,
        NetworkDisconnectedCallback_t xCallback,
        AwsIotDemoNetworkConnection_t* pxIotNetworkConnection );

uint32_t ulGetConnectedNetworkType( AwsIotDemoNetworkConnection_t xNetworkConnection );

void vDeleteNetworkConnection( AwsIotDemoNetworkConnection_t xNetworkConnection );

#endif /* AWS_IOT_DEMO_NETWORK_H_ */