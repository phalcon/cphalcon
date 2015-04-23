
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Mvc\Router\GroupInterface
 *
 *
 *<code>
 * $router = new \Phalcon\Mvc\Router();
 *
 * //Create a group with a common module and controller
 * $blog = new Group(array(
 * 	'module' => 'blog',
 * 	'controller' => 'index'
 * ));
 *
 * //All the routes start with /blog
 * $blog->setPrefix('/blog');
 *
 * //Add a route to the group
 * $blog->add('/save', array(
 * 	'action' => 'save'
 * ));
 *
 * //Add another route to the group
 * $blog->add('/edit/{id}', array(
 * 	'action' => 'edit'
 * ));
 *
 * //This route maps to a controller different than the default
 * $blog->add('/blog', array(
 * 	'controller' => 'about',
 * 	'action' => 'index'
 * ));
 *
 * //Add the group to the router
 * $router->mount($blog);
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Router_GroupInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Router, GroupInterface, phalcon, mvc_router_groupinterface, phalcon_mvc_router_groupinterface_method_entry);

	return SUCCESS;

}

/**
 * Set a hostname restriction for all the routes in the group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setHostname);

/**
 * Returns the hostname restriction
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getHostname);

/**
 * Set a common uri prefix for all the routes in this group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setPrefix);

/**
 * Returns the common prefix for all the routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getPrefix);

/**
 * Sets a callback that is called if the route is matched.
 * The developer can implement any arbitrary conditions here
 * If the callback returns false the route is treated as not matched
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, beforeMatch);

/**
 * Returns the 'before match' callback if any
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getBeforeMatch);

/**
 * Set common paths for all the routes in the group
 *
 * @param array paths
 * @return Phalcon\Mvc\Router\Group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, setPaths);

/**
 * Returns the common paths defined for this group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getPaths);

/**
 * Returns the routes added to the group
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, getRoutes);

/**
 * Adds a route to the router on any HTTP method
 *
 *<code>
 * router->add('/about', 'About::index');
 *</code>
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, add);

/**
 * Adds a route to the router that only match if the HTTP method is GET
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addGet);

/**
 * Adds a route to the router that only match if the HTTP method is POST
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPost);

/**
 * Adds a route to the router that only match if the HTTP method is PUT
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPut);

/**
 * Adds a route to the router that only match if the HTTP method is PATCH
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addPatch);

/**
 * Adds a route to the router that only match if the HTTP method is DELETE
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addDelete);

/**
 * Add a route to the router that only match if the HTTP method is OPTIONS
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addOptions);

/**
 * Adds a route to the router that only match if the HTTP method is HEAD
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, addHead);

/**
 * Removes all the pre-defined routes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Router_GroupInterface, clear);

