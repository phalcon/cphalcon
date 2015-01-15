
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/
namespace Phalcon\Acl\Adapter;

use Phalcon\Db;
use Phalcon\Acl\Adapter;
use Phalcon\Acl\Exception;
use Phalcon\Acl\Resource;
use Phalcon\DiInterface;

/**
 * Phalcon\Acl\Adapter\Database
 * Manages ACL lists in database
 */
class Database extends Adapter
{
	
	protected _db;
	
    /**
     * @var array
     */
    protected _options;

    /**
     * Class constructor.
     *
     * @param  array  options
     * @throws \Phalcon\Acl\Exception
     */
    public function __construct(options = null)
    {
		let this->_options = [];
		if typeof options == "array" {
			if isset options["db"] {
				let this->_db = \Phalcon\Di::getDefault()->getShared(options["db"]);
			}
			if isset options["roles"] {
				let this->_options["roles"]= options["roles"];
			}
			if isset options["resources"] {
				let this->_options["resources"] = options["resources"];
			}
			if isset options["resourcesAccesses"] {
				let this->_options["resourcesAccesses"] = options["resourcesAccesses"];
			}
			if isset options["accessList"] {
				let this->_options["accessList"] = options["accessList"];
			}
			if isset options["rolesInherits"] {
				let this->_options["rolesInherits"] = options["rolesInherits"];
			}
		}
		if typeof this->_db != "object" {
			let this->_db = \Phalcon\Di::getDefault()->getShared("db");
		}
		if !isset this->_options["roles"] {
			let this->_options["roles"] = "roles";
		}
		
		if !isset this->_options["resourcesAccesses"] {
			let this->_options["resourcesAccesses"] = "resources_accesses";
		}
		
		if !this->_db->tableExists(this->_options["resourcesAccesses"])
			throw new Exception("Table '" . this->_options["resourcesAccesses"] . "' does not exist");
		
		if !isset this->_options["resources"] {
			let this->_options["resources"] = "resources";
		}
		if !this->_db->tableExists(this->_options["resources"])
			throw new Exception("Table '" . this->_options["resources"] . "' does not exist");
		
		if !isset this->_options["accessList"] {
			let this->_options["accessList"] = "access_list";
		}
		if !this->_db->tableExists(this->_options["accessList"])
			throw new Exception("Table '" . this->_options["accessList"] . "' does not exist");
		
		if !isset this->_options["rolesInherits"] {
			let this->_options["rolesInherits"] = "roles_inherits";
		}
		if !this->_db->tableExists(this->_options["rolesInherits"])
			throw new Exception("Table '" . this->_options["rolesInherits"] . "' does not exist");
		
		
    }

    /**
	 * Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role
	 *
	 * Example:
	 * <code>
	 * 	$acl->addRole(new $Phalcon\Acl\Role("administrator"), "consultant");
	 * 	$acl->addRole("administrator", "consultant");
	 * </code>
	 *
	 * @param  Phalcon\Acl\RoleInterface role
	 * @param  array|string accessInherits
	 * @return boolean
	 */
    public function addRole(var role, accessInherits = null) -> boolean
    {
		var exists, sql, roleObject;
		
		if typeof role == "object" {
			let roleObject = role;
		} else {
			let roleObject = new \Phalcon\Acl\Role(role);
		}
		
		let sql = "SELECT count(*) FROM " . this->_options["roles"] . " WHERE name = ?";
        let exists =this->_db->fetchOne(sql, null,[roleObject->getName()]);

        if !exists[0] {
			let sql = "INSERT INTO " . this->_options["roles"] . " VALUES (?, ?)";
           this->_db->execute(sql,[roleObject->getName(), roleObject->getDescription()]);
			let sql = "INSERT INTO " . this->_options["accessList"] . " VALUES (?, ?, ?, ?)";
           this->_db->execute(sql,[roleObject->getName(), "*", "*", this->_defaultAccess]);
        }
		else {
			return false;
		}
        if accessInherits != null {
            return this->addInherit(roleObject->getName(), accessInherits);
        }
        return true;
    }

    /**
	 * Do a role inherit from another existing role
	 *
	 * @param string roleName
	 * @param string roleToInherit
	 */
    public function addInherit(var roleName, var roleToInherit)
    {
		var exists;
		
        var sql = "SELECT COUNT(*) FROM ";
		let sql .= this->_options["roles"] . " WHERE name = ?";
		
        let exists =this->_db->fetchOne(sql, null, [roleName]);
        if !exists[0] {
            throw new Exception("Role '" . roleName . "' does not exist in the role list");
        }
		
		let exists =this->_db->fetchOne(sql, null, [roleToInherit]);
        if !exists[0] {
            throw new Exception("Role '" . roleToInherit . "' does not exist in the role list");
        }

        let exists =this->_db->fetchOne(
            "SELECT COUNT(*) FROM " . this->_options["rolesInherits"] . " WHERE roles_name = ? AND roles_inherit = ?",
            null,
            [roleName, roleToInherit]
        );

        if !exists[0] {
           this->_db->execute(
                "INSERT INTO " . this->_options["rolesInherits"] . " VALUES (?, ?)",
                [roleName, roleToInherit]
            );
        }
    }

    /**
	 * Check whether role exist in the roles list
	 *
	 * @param  string roleName
	 * @return boolean
	 */
    public function isRole(var roleName) -> boolean
    {
		var exists;
        let exists =this->_db->fetchOne(
            "SELECT COUNT(*) FROM " . this->_options["roles"] . " WHERE name = ?",
            null,
            [roleName]
        );

        return exists[0];
    }

    /**
	 * Check whether resource exist in the resources list
	 *
	 * @param  string resourceName
	 * @return boolean
	 */
    public function isResource(var resourceName) -> boolean
    {
		var exists;
        let exists =this->_db->fetchOne(
            "SELECT COUNT(*) FROM " . this->_options["resources"] . " WHERE name = ?",
            null,
            [resourceName]
        );

        return exists[0];
    }

    /**
	 * Adds a resource to the ACL list
	 *
	 * Access names can be a particular action, by example
	 * search, update, delete, etc or a list of them
	 *
	 * Example:
	 * <code>
	 * //Add a resource to the the list allowing access to an action
	 * $acl->addResource(new $Phalcon\Acl\Resource("customers"), "search");
	 * $acl->addResource("customers", "search");
	 *
	 * //Add a resource  with an access list
	 * $acl->addResource(new $Phalcon\Acl\Resource("customers"), array("create", "search"));
	 * $acl->addResource("customers", array("create", "search"));
	 * </code>
	 *
	 * @param   Phalcon\Acl\Resource resource
	 * @param   array accessList
	 * @return  boolean
	 */
    public function addResource(var resourceValue, var accessList) -> boolean
    {
	
		var exists, resourceObject;
		
        if typeof resourceValue == "object" {
            let resourceObject = resourceValue;
        }
		else
		{
			let resourceObject = new $Resource(resourceValue);
		}

        let exists = this->_db->fetchOne(
            "SELECT COUNT(*) FROM " . this->_options["resources"] . " WHERE name = ?",
            null,
            [resourceObject->getName()]
        );

        if !$exists[0] {
           this->_db->execute(
                "INSERT INTO " . this->_options["resources"] . " VALUES (?, ?)",
                [resourceObject->getName(), resourceObject->getDescription()]
            );
        }

        if accessList != null {
            return this->addResourceAccess(resourceObject->getName(), accessList);
        }
		
        return true;
    }

    /**
	 * Adds access to resources
	 *
	 * @param string resourceName
	 * @param mixed accessList
	 * @return boolean
	 */
    public function addResourceAccess(var resourceName, var accessList) -> boolean
    {
		var accessName, exists;
        if !this->isResource(resourceName) {
            throw new Exception("Resource '" . resourceName . "' does not exist in ACL");
        }

        var sql = "SELECT COUNT(*) FROM ";
		let sql .= this->_options["resourcesAccesses"] . " WHERE resources_name = ? AND access_name = ?";
        if typeof accessList == "array" {
			for accessName in accessList {
                let exists =this->_db->fetchOne(sql, null, [resourceName, accessName]);
                if !exists[0] {
                   this->_db->execute(
                        "INSERT INTO " . this->_options["resourcesAccesses"] . " VALUES (?, ?)",
                        [resourceName, accessName]
                    );
                }
            }
        } else {
            let exists =this->_db->fetchOne(sql, null, [resourceName, accessList]);
            if !exists[0] {
               this->_db->execute(
                    "INSERT INTO " . this->_options["resourcesAccesses"] . " VALUES (?, ?)",
                    [resourceName, accessList]
                );
            }
        }
        return true;
    }

    /**
	 * Return an array with every resource registered in the list
	 *
	 * @return Phalcon\Acl\Resource[]
	 */
    public function getResources() 
    {
		var row, sql;
        var resources = [];
		let sql = "SELECT * FROM " . this->_options["resources"];
		
        for row in this->_db->fetchAll(sql, Db::FETCH_ASSOC) {
            let resources[] = new $Resource(row["name"], row["description"]);
        }
        return resources;
    }

    /**
	 * Return an array with every role registered in the list
	 *
	 * @return Phalcon\Acl\Role[]
	 */
    public function getRoles()
    {
		var row, sql;
        var roles = [];
        let sql = "SELECT * FROM " . this->_options["roles"];

        for row in this->_db->fetchAll(sql, Db::FETCH_ASSOC) {
            let roles[] = new \Phalcon\Acl\Role(row["name"], row["description"]);
        }
        return roles;
    }

   /**
	 * Removes an access from a resource
	 *
	 * @param string resourceName
	 * @param mixed accessList
	 */
    public function dropResourceAccess(var resourceName, var accessList)
    {
		var accessName, sql;
		
		if !this->isResource(resourceName) {
            throw new Exception("Resource '" . resourceName . "' does not exist in ACL");
        }	
        let sql = "DELETE FROM " .
            this->_options["resourcesAccesses"] .
            " WHERE resources_name = ? AND access_name = ?";
        if typeof accessList == "array" {
			for accessName in accessList {
				this->_options["db"]->execute(sql, [resourceName, accessName]);
            }
        } else {
          this->_db->execute(sql, [resourceName, accessName]);
        }
    }

    /**
	 * Allow access to a role on a resource
	 *
	 * You can use "*" as wildcard
	 *
	 * Example:
	 * <code>
	 * //Allow access to guests to search on customers
	 * $acl->allow("guests", "customers", "search");
	 *
	 * //Allow access to guests to search or create on customers
	 * $acl->allow("guests", "customers", array("search", "create"));
	 *
	 * //Allow access to any role to browse on products
	 * $acl->allow("*", "products", "browse");
	 *
	 * //Allow access to any role to browse on any resource
	 * $acl->allow("*", "*", "browse");
	 * </code>
	 *
	 * @param string roleName
	 * @param string resourceName
	 * @param mixed  access
	 */
    public function allow(var roleName,var resourceName,var access)
    {
		var innerRoleName;
		if roleName != "*" {
			return this->_allowOrDeny(roleName, resourceName, access, \Phalcon\Acl::ALLOW);
		} else {
			for innerRoleName in this->getRoles() {
				this->_allowOrDeny(innerRoleName->getName(), resourceName, access, \Phalcon\Acl::ALLOW);
			}
		}
    }

    /**
	 * Deny access to a role on a resource
	 *
	 * You can use "*" as wildcard
	 *
	 * Example:
	 * <code>
	 * //Deny access to guests to search on customers
	 * $acl->deny("guests", "customers", "search");
	 *
	 * //Deny access to guests to search or create on customers
	 * $acl->deny("guests", "customers", array("search", "create"));
	 *
	 * //Deny access to any role to browse on products
	 * $acl->deny("*", "products", "browse");
	 *
	 * //Deny access to any role to browse on any resource
	 * $acl->deny("*", "*", "browse");
	 * </code>
	 *
	 * @param  string roleName
	 * @param  string resourceName
	 * @param  mixed  access
	 * @return boolean
	 */
    public function deny(var roleName, var resourceName, var access)
    {
		var innerRoleName;

		if roleName != "*" {
			return this->_allowordeny(roleName, resourceName, access, \Phalcon\Acl::DENY);
		} else {
			for innerRoleName in this->getRoles() {
				this->_allowordeny(innerRoleName->getName(), resourceName, access, \Phalcon\Acl::DENY);
			}
		}
    }

   	/**
	  * Check whether a role is allowed to access an action from a resource
	  *
	  * <code>
	  * //Does andres have access to the customers resource to create?
	  * $acl->isAllowed("andres", "Products", "create");
	  *
	  * //Do guests have access to any resource to edit?
	  * $acl->isAllowed("guests", "*", "edit");
	  * </code>
	  *
	  * @param  string roleName
	  * @param  string resourceName
	  * @param  string access
	  * @return int|boolean
	  */
    public function isAllowed(var role, var resourceName, var access) -> boolean
    {
		var allowed, sql;
        let sql = implode(" ", [
            "SELECT allowed FROM", this->_options["accessList"], "AS a",
            // role_name in:
            "WHERE roles_name IN (",
                // given "role"-parameter
                "SELECT ? ",
                // inherited role_names
                "UNION SELECT roles_inherit FROM", this->_options["rolesInherits"], "WHERE roles_name = ?",
                // or "any"
                "UNION SELECT '*'",
            ")",
            // resources_name should be given one or "any"
            "AND resources_name IN (?, '*')",
            // access_name should be given one or "any"
            "AND access_name IN (?, '*')",
            // order be the sum of bools for "literals" before "any"
            "ORDER BY (roles_name != '*')+(resources_name != '*')+(access_name != '*') DESC",
            // get only one...
            "LIMIT 1"
        ]);
        
        // fetch one entry...
        let allowed =this->_db->fetchOne(sql, Db::FETCH_NUM, [role, role, resourceName, access]);
        if typeof allowed == "array" {
            return allowed[0];
        }

        /**
         * Return the default access action
         */

        return this->_defaultAccess;
    }

    /**
     * Inserts/Updates a permission in the access list
     *
     * @param  string                 $roleName
     * @param  string                 $resourceName
     * @param  string                 $accessName
     * @param  integer                $action
     * @return boolean
     * @throws \Phalcon\Acl\Exception
     */
    protected function insertOrUpdateAccess(var roleName, var resourceName, var accessName, var action)
    {
		var exists, params, sql;
		
        /**
         * Check if the access is valid in the resource
         */
        let sql = "SELECT COUNT(*) FROM " .
            this->_options["resourcesAccesses"] .
            " WHERE resources_name = ? AND access_name = ?";
        let exists =this->_db->fetchOne(sql, null, [resourceName, accessName]);
        if !exists[0] {
            throw new Exception(
                "Access '" . accessName . "' does not exist in resource '" . resourceName . "' in ACL"
            );
        }

        /**
         * Update the access in access_list
         */
        let sql = "SELECT COUNT(*) FROM " .
            this->_options["accessList"] .
            " WHERE roles_name = ? AND resources_name = ? AND access_name = ?";
        let exists =this->_db->fetchOne(sql, null, [roleName, resourceName, accessName]);
        if !exists[0] {
            let sql = "INSERT INTO " . this->_options["accessList"] . " VALUES (?, ?, ?, ?)";
            let params = [roleName, resourceName, accessName, action];
        } else {
            let sql = "UPDATE " .
                this->_options["accessList"] .
                " SET allowed = ? WHERE roles_name = ? AND resources_name = ? AND access_name = ?";
            let params = [action, roleName, resourceName, accessName];
        }

       this->_db->execute(sql, params);

        /**
         * Update the access "*" in access_list
         */
        let sql = "SELECT COUNT(*) FROM " .
            this->_options["accessList"] .
            " WHERE roles_name = ? AND resources_name = ? AND access_name = ?";
        let exists =this->_db->fetchOne(sql, null, [roleName, resourceName, "*"]);
        if !exists[0] {
            let sql = "INSERT INTO " . this->_options["accessList"] . " VALUES (?, ?, ?, ?)";
           this->_db->execute(sql, [roleName, resourceName, "*", this->_defaultAccess]);
        }
    }

	/**
	 * Checks if a role has access to a resource
	 *
	 * @param string roleName
	 * @param string resourceName
	 * @param string access
	 * @param string action
	 */
    protected function _allowOrDeny(var roleName, var resourceName, var access, var action)
    {
		var accessName;
        if !this->isRole(roleName) {
            throw new Exception("Role '" . roleName . "' does not exist in the list");
        }

        if typeof access == "array" {
            for accessName in access {
                this->insertOrUpdateAccess(roleName, resourceName, accessName, action);
            }
        } else {
            this->insertOrUpdateAccess(roleName, resourceName, access, action);
        }
    }
}
