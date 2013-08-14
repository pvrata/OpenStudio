/**********************************************************************
* Copyright (c) 2008-2013, Alliance for Sustainable Energy.  
*  All rights reserved.
*  
*  This library is free software; you can redistribute it and/or
*  modify it under the terms of the GNU Lesser General Public
*  License as published by the Free Software Foundation; either
*  version 2.1 of the License, or (at your option) any later version.
*  
*  This library is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*  Lesser General Public License for more details.
*  
*  You should have received a copy of the GNU Lesser General Public
*  License along with this library; if not, write to the Free Software
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**********************************************************************/

#ifndef UTILITIES_CLOUD_CLOUDPROVIDER_HPP
#define UTILITIES_CLOUD_CLOUDPROVIDER_HPP

#include <utilities/UtilitiesAPI.hpp>
#include <utilities/core/Optional.hpp>
#include <utilities/core/UUID.hpp>

#include <QObject>

class QUrl;

namespace openstudio{

  /// CloudProvider is an abstract base class for classes that provide cloud resources.
  class UTILITIES_API CloudProvider : public QObject {

    Q_OBJECT

  public:

    /** @name Constructor */
    //@{

    /// constructor
    CloudProvider();

    //@}
    /** @name Destructors */
    //@{

    /// virtual destructor
    virtual ~CloudProvider();

    //@}
    /** @name Class members */
    //@{
    
    /// returns true if this computer is connected to the internet
    /// blocking call, clears errors and warnings
    virtual bool internetAvailable() const = 0;

    /// returns true if the cloud service can be reached (e.g. ping)
    /// blocking call, clears errors and warnings
    virtual bool serviceAvailable() const = 0;

    /// returns true if the cloud service validates user credentials
    /// blocking call, clears errors and warnings
    virtual bool validateCredentials() const = 0;

    /// returns the current session id
    /// blocking call
    virtual UUID sessionID() const = 0;

    /// returns true if can connect to a previously started sessionID using data in QSettings
    /// blocking call, clears errors and warnings
    virtual bool reconnect(const UUID& sessionID) = 0;

    /// returns the ip address of the cloud server if it is started and running
    virtual boost::optional<QUrl> serverAddress() const;

    /// returns true if the cloud server successfully begins to start the server node
    /// returns false if terminated
    /// non-blocking call, clears errors and warnings
    virtual bool startServer() = 0;

    /// returns the ip address of all cloud workers that are started and running
    virtual std::vector<QUrl> workerAddresses() const;

    /// returns the number of workers to be requested
    virtual unsigned numWorkers() const = 0;

    /// returns true if the cloud server successfully begins to start all worker nodes
    /// returns false if terminated
    /// non-blocking call, clears errors and warnings
    virtual bool startWorkers() = 0;

    /// returns true if the server and all workers are running
    virtual bool running() const = 0;

    /// returns true if the cloud server successfully begins to stop all nodes
    /// returns false if not running
    /// non-blocking call, clears errors and warnings
    virtual bool terminate() = 0;

    /// returns true if terminate has been called
    virtual bool terminated() const = 0;

    /// returns errors generated by the last operation
    virtual std::vector<std::string> errors() const = 0;
    
    /// returns warnings generated by the last operation
    virtual std::vector<std::string> warnings() const = 0;

    //@}
  protected:
    
    /// saves this session to the user's QSettings, called whenever node is started
    /// blocking call, clears errors and warnings    
    virtual bool save() const = 0;

    /// removes this session from the user's QSettings, called after session terminates
    /// blocking call, clears errors and warnings    
    virtual bool remove() const = 0;

  signals:
    
    /// emitted when the server is starting
    void serverStarting();

    /// emitted when the server has been started
    void serverStarted(const QUrl& url);

    /// emitted when a worker is starting
    void workerStarting();

    /// emitted when a worker has been started
    void workerStarted(const QUrl& url);

    /// emitted when all nodes have been started
    void allWorkersStarted();

    /// emitted when all nodes have begun to shut down
    void terminating();

    /// emitted when all nodes have been shut down
    void terminated();

  private:

    // no body on purpose, do not want this generated
    CloudProvider(const CloudProvider& other);

  };

} // openstudio

#endif // UTILITIES_CLOUD_CLOUDPROVIDER_HPP
