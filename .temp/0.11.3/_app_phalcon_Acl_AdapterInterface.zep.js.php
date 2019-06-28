<?php return array (
  0 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *',
    'file' => '/app/phalcon/Acl/AdapterInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Acl',
    'file' => '/app/phalcon/Acl/AdapterInterface.zep',
    'line' => 15,
    'char' => 2,
  ),
  2 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Interface for Phalcon\\Acl adapters
 *',
    'file' => '/app/phalcon/Acl/AdapterInterface.zep',
    'line' => 16,
    'char' => 9,
  ),
  3 => 
  array (
    'type' => 'interface',
    'name' => 'AdapterInterface',
    'definition' => 
    array (
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addInherit',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'roleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 21,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'roleToInherit',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 21,
              'char' => 62,
            ),
          ),
          'docblock' => '**
     * Do a role inherit from another existing role
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 21,
                'char' => 71,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 21,
            'char' => 71,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 21,
          'last-line' => 26,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addRole',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'role',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 27,
              'char' => 33,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'accessInherits',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 27,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 27,
              'char' => 56,
            ),
          ),
          'docblock' => '**
     * Adds a role to the ACL list. Second parameter lets to inherit access data
     * from other existing role
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 27,
                'char' => 65,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 27,
            'char' => 65,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 27,
          'last-line' => 34,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addComponent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'componentObject',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 35,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'accessList',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 35,
              'char' => 61,
            ),
          ),
          'docblock' => '**
     * Adds a component to the ACL list
     *
     * Access names can be a particular action, by example
     * search, update, delete, etc or a list of them
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 35,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 35,
            'char' => 70,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 35,
          'last-line' => 39,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'addComponentAccess',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 40,
              'char' => 60,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'accessList',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 40,
              'char' => 72,
            ),
          ),
          'docblock' => '**
     * Adds access to components
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 40,
                'char' => 81,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 40,
            'char' => 81,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 40,
          'last-line' => 44,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'allow',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'roleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 45,
              'char' => 42,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 45,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 45,
              'char' => 72,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'func',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 45,
                'char' => 85,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 45,
              'char' => 85,
            ),
          ),
          'docblock' => '**
     * Allow access to a role on a component
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 45,
            'char' => 94,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'deny',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'roleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 50,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 50,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 50,
              'char' => 71,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'func',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 50,
                'char' => 84,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 50,
              'char' => 84,
            ),
          ),
          'docblock' => '**
     * Deny access to a role on a component
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 50,
            'char' => 93,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 50,
          'last-line' => 54,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'dropComponentAccess',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 55,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'accessList',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 55,
              'char' => 73,
            ),
          ),
          'docblock' => '**
     * Removes an access from a component
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 55,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 55,
          'last-line' => 59,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveAccess',
          'docblock' => '**
     * Returns the access which the list is checking if some role can access it
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 60,
                'char' => 48,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 60,
            'char' => 48,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 60,
          'last-line' => 65,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveRole',
          'docblock' => '**
     * Returns the role which the list is checking if it\'s allowed to certain
     * component/access
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 66,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 66,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 66,
          'last-line' => 71,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getActiveComponent',
          'docblock' => '**
     * Returns the component which the list is checking if some role can access
     * it
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'string',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 72,
                'char' => 51,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 72,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 72,
          'last-line' => 76,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultAction',
          'docblock' => '**
     * Returns the default ACL access level
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 77,
                'char' => 46,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 77,
            'char' => 46,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 77,
          'last-line' => 82,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getNoArgumentsDefaultAction',
          'docblock' => '**
     * Returns the default ACL access level for no arguments provided in
     * isAllowed action if there exists func for accessKey
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'int',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 83,
                'char' => 57,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 83,
            'char' => 57,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 83,
          'last-line' => 87,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRoles',
          'docblock' => '**
     * Return an array with every role registered in the list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'RoleInterface',
                  'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                  'line' => 88,
                  'char' => 52,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 88,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 88,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 88,
          'last-line' => 92,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getComponents',
          'docblock' => '**
     * Return an array with every component registered in the list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'cast' => 
                array (
                  'type' => 'variable',
                  'value' => 'ComponentInterface',
                  'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                  'line' => 93,
                  'char' => 62,
                ),
                'collection' => 1,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 93,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 93,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 93,
          'last-line' => 97,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isAllowed',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'roleName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 98,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 98,
              'char' => 54,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'access',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 98,
              'char' => 69,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 98,
                'char' => 94,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 98,
              'char' => 94,
            ),
          ),
          'docblock' => '**
     * Check whether a role is allowed to access an action from a component
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 98,
                'char' => 103,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 98,
            'char' => 103,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 98,
          'last-line' => 102,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isComponent',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'componentName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 103,
              'char' => 53,
            ),
          ),
          'docblock' => '**
     * Check whether component exist in the components list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 103,
                'char' => 62,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 103,
            'char' => 62,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 103,
          'last-line' => 107,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isRole',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'roleName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 108,
              'char' => 43,
            ),
          ),
          'docblock' => '**
     * Check whether role exist in the roles list
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Acl/AdapterInterface.zep',
                'line' => 108,
                'char' => 52,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 108,
            'char' => 52,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 108,
          'last-line' => 112,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultAction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultAccess',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 113,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 113,
            'char' => 64,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 113,
          'last-line' => 119,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setNoArgumentsDefaultAction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultAccess',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/AdapterInterface.zep',
              'line' => 120,
              'char' => 66,
            ),
          ),
          'docblock' => '**
     * Sets the default access level (Phalcon\\Acl::ALLOW or Phalcon\\Acl::DENY)
     * for no arguments provided in isAllowed action if there exists func for
     * accessKey
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/AdapterInterface.zep',
            'line' => 120,
            'char' => 75,
          ),
          'file' => '/app/phalcon/Acl/AdapterInterface.zep',
          'line' => 120,
          'last-line' => 121,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Acl/AdapterInterface.zep',
      'line' => 121,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Acl/AdapterInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);