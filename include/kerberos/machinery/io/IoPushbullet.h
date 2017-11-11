//
//  Class: IoPushbullet
//  Description: A pushbullet class that posts to a specific URL.
//  Created:     25/07/2015
//  Author:      Cédric Verstraeten
//  Mail:        cedric@verstraeten.io
//  Website:     www.verstraeten.io
//
//  The copyright to the computer program(s) herein
//  is the property of Verstraeten.io, Belgium.
//  The program(s) may be used and/or copied under
//  the CC-NC-ND license model.
//
//  https://doc.kerberos.io/license
//
/////////////////////////////////////////////////////

#ifndef __IoPushbullet_H_INCLUDED__   // if IoPushbullet.h hasn't been included yet...
#define __IoPushbullet_H_INCLUDED__   // #define this so the compiler knows it has been included

#include "machinery/io/Io.h"
#include "document.h"
#include "writer.h"
#include "restclient-cpp/connection.h"
#include "restclient-cpp/restclient.h"
#include "Throttler.h"

namespace kerberos
{
    char PushbulletName[] = "Pushbullet";
    class IoPushbullet : public IoCreator<PushbulletName, IoPushbullet>
    {
        private:
            std::string m_url;
            std::string m_instanceName;
            std::string m_pbToken;
            RestClient::Connection * pushbulletConnection;
            Throttler throttle;

        public:
            IoPushbullet(){};
            virtual ~IoPushbullet()
            {
                delete pushbulletConnection;
            };
            void setup(const StringMap & settings);
            void fire(JSON & data){};
            void disableCapture(){};

            void setUrl(std::string url){m_url=url;};
            const char * getUrl(){return m_url.c_str();};
            void setToken(std::string token){m_pbToken=token;};
            const char * getToken(){return m_pbToken.c_str();};
            void setInstanceName(std::string instanceName){m_instanceName=instanceName;};
            std::string getInstanceName(){return m_instanceName;};

            bool save(Image & image){ return true; };
            bool save(Image & image, JSON & data);
    };
}
#endif
