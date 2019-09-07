---
layout: default
language: 'en'
version: '4.0'
title: 'Phalcon\Acl'
---

* [Phalcon\Acl\Adapter\AbstractAdapter](#acl-adapter-abstractadapter)
* [Phalcon\Acl\Adapter\AdapterInterface](#acl-adapter-adapterinterface)
* [Phalcon\Acl\Adapter\Memory](#acl-adapter-memory)
* [Phalcon\Acl\Component](#acl-component)
* [Phalcon\Acl\ComponentAware](#acl-componentaware)
* [Phalcon\Acl\ComponentInterface](#acl-componentinterface)
* [Phalcon\Acl\Enum](#acl-enum)
* [Phalcon\Acl\Exception](#acl-exception)
* [Phalcon\Acl\Role](#acl-role)
* [Phalcon\Acl\RoleAware](#acl-roleaware)
* [Phalcon\Acl\RoleInterface](#acl-roleinterface)
        
<h1 id="acl-adapter-abstractadapter">Abstract Class Phalcon\Acl\Adapter\AbstractAdapter</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/adapter/abstractadapter.zep)

| Namespace  | Phalcon\Acl\Adapter |
| Uses       | Phalcon\Events\ManagerInterface, Phalcon\Events\EventsAwareInterface |
| Implements | AdapterInterface, EventsAwareInterface |

Adapter for Phalcon\Acl adapters


## Properties
```php
/**
 * Active access which the list is checking if some role can access it
 *
 * @var string
 */
protected activeAccess;

/**
 * Access Granted
 *
 * @var bool
 */
protected accessGranted = false;

/**
 * Role which the list is checking if it's allowed to certain
 * component/access
 *
 * @var string
 */
protected activeRole;

/**
 * Component which the list is checking if some role can access it
 *
 * @var string
 */
protected activeComponent;

/**
 * Default access
 *
 * @var bool
 */
protected defaultAccess = false;

/**
 * Events manager
 *
 * @var mixed
 */
protected eventsManager;

```

## Methods
```php
public function getActiveAccess(): string
```


```php
public function getActiveComponent(): string
```


```php
public function getActiveRole(): string
```


```php
public function getDefaultAction(): int;
```
Returns the default ACL access level


```php
public function getEventsManager(): ManagerInterface;
```
Returns the internal event manager


```php
public function setDefaultAction( int $defaultAccess );
```
Sets the default access level (Phalcon\Acl::ALLOW or Phalcon\Acl::DENY)


```php
public function setEventsManager( ManagerInterface $eventsManager ): void;
```
Sets the events manager



        
<h1 id="acl-adapter-adapterinterface">Interface Phalcon\Acl\Adapter\AdapterInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/adapter/adapterinterface.zep)

| Namespace  | Phalcon\Acl\Adapter |

Interface for Phalcon\Acl adapters


## Methods
```php
public function addComponent( mixed $componentObject, mixed $accessList ): bool;
```
Adds a component to the ACL list

Access names can be a particular action, by example
search, update, delete, etc or a list of them


```php
public function addComponentAccess( string $componentName, mixed $accessList ): bool;
```
Adds access to components


```php
public function addInherit( string $roleName, mixed $roleToInherit ): bool;
```
Do a role inherit from another existing role


```php
public function addRole( mixed $role, mixed $accessInherits = null ): bool;
```
Adds a role to the ACL list. Second parameter lets to inherit access data
from other existing role


```php
public function allow( string $roleName, string $componentName, mixed $access, mixed $func = null ): void;
```
Allow access to a role on a component


```php
public function deny( string $roleName, string $componentName, mixed $access, mixed $func = null ): void;
```
Deny access to a role on a component


```php
public function dropComponentAccess( string $componentName, mixed $accessList ): void;
```
Removes an access from a component


```php
public function getActiveAccess(): string;
```
Returns the access which the list is checking if some role can access it


```php
public function getActiveComponent(): string;
```
Returns the component which the list is checking if some role can access
it


```php
public function getActiveRole(): string;
```
Returns the role which the list is checking if it's allowed to certain
component/access


```php
public function getComponents(): ComponentInterface[];
```
Return an array with every component registered in the list


```php
public function getDefaultAction(): int;
```
Returns the default ACL access level


```php
public function getNoArgumentsDefaultAction(): int;
```
Returns the default ACL access level for no arguments provided in
isAllowed action if there exists func for accessKey


```php
public function getRoles(): RoleInterface[];
```
Return an array with every role registered in the list


```php
public function isAllowed( mixed $roleName, mixed $componentName, string $access, array $parameters = null ): bool;
```
Check whether a role is allowed to access an action from a component


```php
public function isComponent( string $componentName ): bool;
```
Check whether component exist in the components list


```php
public function isRole( string $roleName ): bool;
```
Check whether role exist in the roles list


```php
public function setDefaultAction( int $defaultAccess ): void;
```
Sets the default access level (Phalcon\Ac\Enuml::ALLOW or Phalcon\Acl\Enum::DENY)


```php
public function setNoArgumentsDefaultAction( int $defaultAccess ): void;
```
Sets the default access level (Phalcon\Acl\Enum::ALLOW or Phalcon\Acl\Enum::DENY)
for no arguments provided in isAllowed action if there exists func for
accessKey



        
<h1 id="acl-adapter-memory">Class Phalcon\Acl\Adapter\Memory</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/adapter/memory.zep)

| Namespace  | Phalcon\Acl\Adapter |
| Uses       | Phalcon\Acl\Adapter\AbstractAdapter, Phalcon\Acl\Enum, Phalcon\Acl\Role, Phalcon\Acl\RoleInterface, Phalcon\Acl\Component, Phalcon\Acl\Exception, Phalcon\Events\Manager, Phalcon\Acl\RoleAware, Phalcon\Acl\ComponentAware, Phalcon\Acl\RoleInterface, Phalcon\Acl\ComponentInterface, ReflectionFunction |
| Extends    | AbstractAdapter |

Manages ACL lists in memory

```php
$acl = new \Phalcon\Acl\Adapter\Memory();

$acl->setDefaultAction(
    \Phalcon\Acl\Enum::DENY
);

// Register roles
$roles = [
    "users"  => new \Phalcon\Acl\Role("Users"),
    "guests" => new \Phalcon\Acl\Role("Guests"),
];
foreach ($roles as $role) {
    $acl->addRole($role);
}

// Private area components
$privateComponents = [
    "companies" => ["index", "search", "new", "edit", "save", "create", "delete"],
    "products"  => ["index", "search", "new", "edit", "save", "create", "delete"],
    "invoices"  => ["index", "profile"],
];

foreach ($privateComponents as $componentName => $actions) {
    $acl->addComponent(
        new \Phalcon\Acl\Component($componentName),
        $actions
    );
}

// Public area components
$publicComponents = [
    "index"   => ["index"],
    "about"   => ["index"],
    "session" => ["index", "register", "start", "end"],
    "contact" => ["index", "send"],
];

foreach ($publicComponents as $componentName => $actions) {
    $acl->addComponent(
        new \Phalcon\Acl\Component($componentName),
        $actions
    );
}

// Grant access to public areas to both users and guests
foreach ($roles as $role) {
    foreach ($publicComponents as $component => $actions) {
        $acl->allow($role->getName(), $component, "*");
    }
}

// Grant access to private area to role Users
foreach ($privateComponents as $component => $actions) {
    foreach ($actions as $action) {
        $acl->allow("Users", $component, $action);
    }
}
```


## Properties
```php
/**
 * Access
 *
 * @var mixed
 */
protected access;

/**
 * Access List
 *
 * @var mixed
 */
protected accessList;

/**
 * Returns latest function used to acquire access
 *
 * @var mixed
 */
protected activeFunction;

/**
 * Returns number of additional arguments(excluding role and resource) for active function
 *
 * @var int
 */
protected activeFunctionCustomArgumentsCount = 0;

/**
 * Returns latest key used to acquire access
 *
 * @var string|null
 */
protected activeKey;

/**
 * Components
 *
 * @var mixed
 */
protected components;

/**
 * Component Names
 *
 * @var mixed
 */
protected componentsNames;

/**
 * Function List
 *
 * @var mixed
 */
protected func;

/**
 * Default action for no arguments is allow
 *
 * @var mixed
 */
protected noArgumentsDefaultAction;

/**
 * Roles
 *
 * @var mixed
 */
protected roles;

/**
 * Role Inherits
 *
 * @var mixed
 */
protected roleInherits;

/**
 * Roles Names
 *
 * @var mixed
 */
protected rolesNames;

```

## Methods
```php
public function __construct(): void;
```
Phalcon\Acl\Adapter\Memory constructor


```php
public function addComponent( mixed $componentValue, mixed $accessList ): bool;
```
Adds a component to the ACL list

Access names can be a particular action, by example
search, update, delete, etc or a list of them

Example:
```php
// Add a component to the the list allowing access to an action
$acl->addComponent(
    new Phalcon\Acl\Component("customers"),
    "search"
);

$acl->addComponent("customers", "search");

// Add a component  with an access list
$acl->addComponent(
    new Phalcon\Acl\Component("customers"),
    [
        "create",
        "search",
    ]
);

$acl->addComponent(
    "customers",
    [
        "create",
        "search",
    ]
);
```


```php
public function addComponentAccess( string $componentName, mixed $accessList ): bool;
```
Adds access to components


```php
public function addInherit( string $roleName, mixed $roleToInherits ): bool;
```
Do a role inherit from another existing role

```php
$acl->addRole("administrator", "consultant");
$acl->addRole("administrator", ["consultant", "consultant2"]);
```


```php
public function addRole( mixed $role, mixed $accessInherits = null ): bool;
```
Adds a role to the ACL list. Second parameter allows inheriting access data from other existing role

```php
$acl->addRole(
    new Phalcon\Acl\Role("administrator"),
    "consultant"
);

$acl->addRole("administrator", "consultant");
$acl->addRole("administrator", ["consultant", "consultant2"]);
```


```php
public function allow( string $roleName, string $componentName, mixed $access, mixed $func = null ): void;
```
Allow access to a role on a component. You can use `*` as wildcard

```php
// Allow access to guests to search on customers
$acl->allow("guests", "customers", "search");

// Allow access to guests to search or create on customers
$acl->allow("guests", "customers", ["search", "create"]);

// Allow access to any role to browse on products
$acl->allow("*", "products", "browse");

// Allow access to any role to browse on any component
$acl->allow("*", "*", "browse");


```php
public function deny( string $roleName, string $componentName, mixed $access, mixed $func = null ): void;
```
Deny access to a role on a component. You can use `*` as wildcard

```php
// Deny access to guests to search on customers
$acl->deny("guests", "customers", "search");

// Deny access to guests to search or create on customers
$acl->deny("guests", "customers", ["search", "create"]);

// Deny access to any role to browse on products
$acl->deny("*", "products", "browse");

// Deny access to any role to browse on any component
$acl->deny("*", "*", "browse");
```


```php
public function dropComponentAccess( string $componentName, mixed $accessList ): void;
```
Removes an access from a component


```php
public function getActiveFunction(): mixed
```


```php
public function getActiveFunctionCustomArgumentsCount(): int
```


```php
public function getActiveKey(): string|null
```


```php
public function getComponents(): ComponentInterface[];
```
Return an array with every component registered in the list


```php
public function getNoArgumentsDefaultAction(): int;
```
Returns the default ACL access level for no arguments provided in
`isAllowed` action if a `func` (callable) exists for `accessKey`


```php
public function getRoles(): RoleInterface[];
```
Return an array with every role registered in the list


```php
public function isAllowed( mixed $roleName, mixed $componentName, string $access, array $parameters = null ): bool;
```
Check whether a role is allowed to access an action from a component

```php
// Does andres have access to the customers component to create?
$acl->isAllowed("andres", "Products", "create");

// Do guests have access to any component to edit?
$acl->isAllowed("guests", "*", "edit");
```


```php
public function isComponent( string $componentName ): bool;
```
Check whether component exist in the components list


```php
public function isRole( string $roleName ): bool;
```
Check whether role exist in the roles list


```php
public function setNoArgumentsDefaultAction( int $defaultAccess ): void;
```
Sets the default access level (`Phalcon\Enum::ALLOW` or `Phalcon\Enum::DENY`)
for no arguments provided in isAllowed action if there exists func for
accessKey



        
<h1 id="acl-component">Class Phalcon\Acl\Component</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/component.zep)

| Namespace  | Phalcon\Acl |
| Uses       | Phalcon\Acl\Exception |
| Implements | ComponentInterface |

This class defines component entity and its description


## Properties
```php
/**
 * Component description
 *
 * @var string
 */
private description;

/**
 * Component name
 *
 * @var string
 */
private name;

```

## Methods
```php
public function __construct( string $name, string $description = null ): void;
```
Phalcon\Acl\Component constructor


```php
public function __toString(): string
```


```php
public function getDescription(): string
```


```php
public function getName(): string
```



        
<h1 id="acl-componentaware">Interface Phalcon\Acl\ComponentAware</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/componentaware.zep)

| Namespace  | Phalcon\Acl |

Interface for classes which could be used in allow method as RESOURCE


## Methods
```php
public function getComponentName(): string;
```
Returns component name



        
<h1 id="acl-componentinterface">Interface Phalcon\Acl\ComponentInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/componentinterface.zep)

| Namespace  | Phalcon\Acl |

Interface for Phalcon\Acl\Component


## Methods
```php
public function __toString(): string;
```
Magic method __toString


```php
public function getDescription(): string;
```
Returns component description


```php
public function getName(): string;
```
Returns the component name



        
<h1 id="acl-enum">Class Phalcon\Acl\Enum</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/enum.zep)

| Namespace  | Phalcon\Acl |

Constants for Phalcon\Acl\Adapter adapters


## Constants
```php
const ALLOW = 1;
const DENY = 0;
```

        
<h1 id="acl-exception">Class Phalcon\Acl\Exception</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/exception.zep)

| Namespace  | Phalcon\Acl |
| Extends    | \Phalcon\Exception |

Class for exceptions thrown by Phalcon\Acl


        
<h1 id="acl-role">Class Phalcon\Acl\Role</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/role.zep)

| Namespace  | Phalcon\Acl |
| Uses       | Phalcon\Acl\Exception |
| Implements | RoleInterface |

This class defines role entity and its description


## Properties
```php
/**
 * Role name
 *
 * @var string
 */
private name;

/**
 * Role description
 *
 * @var string
 */
private description;

```

## Methods
```php
public function __construct( string $name, string $description = null ): void;
```
Phalcon\Acl\Role constructor


```php
public function __toString(): string
```


```php
public function getDescription(): string
```


```php
public function getName(): string
```



        
<h1 id="acl-roleaware">Interface Phalcon\Acl\RoleAware</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/roleaware.zep)

| Namespace  | Phalcon\Acl |

Interface for classes which could be used in allow method as ROLE


## Methods
```php
public function getRoleName(): string;
```
Returns role name



        
<h1 id="acl-roleinterface">Interface Phalcon\Acl\RoleInterface</h1>

[Source on GitHub](https://github.com/phalcon/cphalcon/tree/v{{ page.version }}.0/phalcon/acl/roleinterface.zep)

| Namespace  | Phalcon\Acl |

Interface for Phalcon\Acl\Role


## Methods
```php
public function __toString(): string;
```
Magic method __toString


```php
public function getDescription(): string;
```
Returns role description


```php
public function getName(): string;
```
Returns the role name


