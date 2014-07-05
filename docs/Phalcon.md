# Phalcon beginner's handbook

*Author: Dreamsxin*

## Benefits

- The Fastest
- Few Memory Usage
- Cross-Platform
- Highly Decoupled
- Full-stack Framework

## Startup Process

    1.Register an autoloader
    2.Create a DI - Phalcon\DI\FactoryDefault
    3.Setup the view component
    4.Setup a base URI 
    5.Handle the request - Phalcon\Mvc\Application::handle
        5.1.Fire event – application:boot
        5.2.Handle the URI pattern (if any)
        5.3.Process the module definition (if any)
		    5.3.1. Fire event  - application:beforeStartModule
		    5.3.2. Call method registerAutoloaders
		    5.3.3.Call method registerServices
		    5.3.3.Fire event - application:afterStartModule
	    5.4.Fire event – application:beforeHandleRequest
	    5.5.Dispatch – Phalcon\Mvc\Dispatcher::dispatch → Phalcon\Dispatcher::dispatch
		    5.5.1Fire event - dispatch:beforeDispatchLoop
		    5.5.2Dispatch loop
		    	5.5.2.1.Fire event - dispatch:beforeDispatch
		    	5.5.2.2.Create the complete controller class name
		    	5.5.2.3.Load controller class
		    	5.5.2.3.Check if the action exists in the controller
		    	5.5.2.4.Fire event - dispatch:beforeExecuteRoute
		    	5.5.2.5.Call the controller method beforeExecuteroute
		    	5.5.2.5.Call the controller method initialize
		    	5.5.2.4.Fire event - dispatch:afterInitialize
		    	5.5.2.5.Call the action
		    	5.5.2.6.Fire event - dispatch:afterExecuteRoute
			    5.5.2.7.Fire event  - dispatch:afterDispatch
		    	5.5.2.8.Call the controller method afterExecuteroute
		    	5.5.2.9.Fire event - dispatch:afterDispatchLoop
		    	5.5.2.10.Retrun the controller
            5.6.Fire event – application:afterHandleRequest
	        5.7.Rendering Views
		        5.7.1.Fire event - application:viewRender
	        	5.7.2.Call method – Phalcon\Mvc\View::render
			        5.7.2.1.Load the template engines
		        	5.7.2.2.Fire event  - view:beforeRender
		        	5.7.2.3.Hierarchical Rendering
				        5.7.2.3.1Render action view 
			        	5.7.2.3.2Render before layout view
			        	5.7.2.3.3Render controller layout view
			        	5.7.2.3.3Render after layout view
			        	5.7.2.3.3Render main view
		        	5.7.2.4.Fire event - view:afterRender
	        5.8.Get the processed content - Phalcon\Mvc\View::getContent
        	5.9.Fire event - application:beforeSendResponse
        	5.10.Send headers - Phalcon\Http\Response::sendHeaders
	        5.11.Send cookies – Phalcon\Http\Response::sendCookies
	        5.12.Return the response