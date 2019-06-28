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
    'file' => '/app/phalcon/Acl/Role.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Acl',
    'file' => '/app/phalcon/Acl/Role.zep',
    'line' => 13,
    'char' => 3,
  ),
  2 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Acl\\Exception',
        'file' => '/app/phalcon/Acl/Role.zep',
        'line' => 13,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Acl/Role.zep',
    'line' => 17,
    'char' => 2,
  ),
  3 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This class defines role entity and its description
 *',
    'file' => '/app/phalcon/Acl/Role.zep',
    'line' => 18,
    'char' => 5,
  ),
  4 => 
  array (
    'type' => 'class',
    'name' => 'Role',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'RoleInterface',
        'file' => '/app/phalcon/Acl/Role.zep',
        'line' => 19,
        'char' => 1,
      ),
    ),
    'definition' => 
    array (
      'properties' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'name',
          'docblock' => '**
     * Role name
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 25,
              'char' => 23,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => '__toString',
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 25,
              'char' => 36,
            ),
          ),
          'file' => '/app/phalcon/Acl/Role.zep',
          'line' => 31,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'private',
          ),
          'type' => 'property',
          'name' => 'description',
          'docblock' => '**
     * Role description
     *
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 32,
              'char' => 31,
            ),
          ),
          'file' => '/app/phalcon/Acl/Role.zep',
          'line' => 36,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 37,
              'char' => 45,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'description',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Acl/Role.zep',
                'line' => 37,
                'char' => 72,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 37,
              'char' => 72,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Acl/Role.zep',
                    'line' => 39,
                    'char' => 27,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '*',
                    'file' => '/app/phalcon/Acl/Role.zep',
                    'line' => 39,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Acl/Role.zep',
                  'line' => 39,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Acl/Role.zep',
                'line' => 39,
                'char' => 31,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Exception',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'Role name cannot be \'*\'',
                          'file' => '/app/phalcon/Acl/Role.zep',
                          'line' => 40,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Acl/Role.zep',
                        'line' => 40,
                        'char' => 56,
                      ),
                    ),
                    'file' => '/app/phalcon/Acl/Role.zep',
                    'line' => 40,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Acl/Role.zep',
                  'line' => 41,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 43,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Acl/Role.zep',
                    'line' => 43,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Acl/Role.zep',
                  'line' => 43,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'description',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'description',
                    'file' => '/app/phalcon/Acl/Role.zep',
                    'line' => 44,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Acl/Role.zep',
                  'line' => 44,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Acl/Role.zep',
              'line' => 45,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Acl\\Role constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Acl/Role.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Acl/Role.zep',
          'line' => 37,
          'last-line' => 46,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Acl/Role.zep',
      'line' => 18,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Acl/Role.zep',
    'line' => 18,
    'char' => 5,
  ),
);