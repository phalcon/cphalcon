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
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Di',
    'file' => '/app/phalcon/Di/Service.zep',
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
        'name' => 'Closure',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 14,
    'char' => 3,
  ),
  3 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 15,
    'char' => 3,
  ),
  4 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\Exception',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 15,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 16,
    'char' => 3,
  ),
  5 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\Exception\\ServiceResolutionException',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 16,
        'char' => 52,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 17,
    'char' => 3,
  ),
  6 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\ServiceInterface',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 17,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 18,
    'char' => 3,
  ),
  7 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Di\\Service\\Builder',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 18,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 31,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Represents individually a service in the services container
 *
 *```php
 * $service = new \\Phalcon\\Di\\Service(
 *     "request",
 *     \\Phalcon\\Http\\Request::class
 * );
 *
 * $request = service->resolve();
 *```
 *',
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 32,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Service',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ServiceInterface',
        'file' => '/app/phalcon/Di/Service.zep',
        'line' => 33,
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
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'definition',
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 38,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'resolved',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 39,
            'char' => 31,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 43,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'shared',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 44,
            'char' => 29,
          ),
          'docblock' => '**
     * @var bool
     *',
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 46,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'sharedInstance',
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 50,
          'char' => 6,
        ),
      ),
      'methods' => 
      array (
        0 => 
        array (
          'visibility' => 
          array (
            0 => 'final',
            1 => 'public',
          ),
          'type' => 'method',
          'name' => '__construct',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 51,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 51,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 51,
              'char' => 74,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 53,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 53,
                  'char' => 42,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'shared',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'shared',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 54,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 54,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Di\\Service
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 52,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 51,
          'last-line' => 59,
          'char' => 25,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
            1 => 'static',
          ),
          'type' => 'method',
          'name' => '__set_state',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'attributes',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 60,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 62,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'shared',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 62,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 64,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 64,
                      'char' => 64,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 64,
                        'char' => 50,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_definition',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 64,
                        'char' => 62,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 64,
                      'char' => 64,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 64,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 64,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 64,
                'char' => 64,
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
                          'value' => 'The attribute \'_definition\' is required',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 65,
                          'char' => 72,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 65,
                        'char' => 72,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 65,
                    'char' => 73,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 66,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 68,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'shared',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 68,
                      'char' => 56,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'attributes',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 68,
                        'char' => 46,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '_shared',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 68,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 68,
                      'char' => 56,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 68,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 68,
                  'char' => 56,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 68,
                'char' => 56,
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
                          'value' => 'The attribute \'_shared\' is required',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 69,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 69,
                        'char' => 68,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 69,
                    'char' => 69,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 72,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'new',
                'class' => 'self',
                'dynamic' => 0,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 72,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 72,
                    'char' => 35,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'shared',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 72,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 72,
                    'char' => 43,
                  ),
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 72,
                'char' => 44,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 73,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Restore the internal state of a service
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 61,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 61,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 60,
          'last-line' => 77,
          'char' => 26,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefinition',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 80,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'definition',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 80,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 80,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 81,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the service definition
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 79,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 79,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 78,
          'last-line' => 87,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 88,
              'char' => 46,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 90,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 90,
                  'char' => 34,
                ),
                2 => 
                array (
                  'variable' => 'parameter',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 90,
                  'char' => 45,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 92,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 92,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 92,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 92,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 92,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 94,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 94,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 94,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 94,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 94,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 94,
                'char' => 48,
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
                          'value' => 'Definition must be an array to obtain its parameters',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 97,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 97,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 97,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 98,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 103,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'arguments',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 103,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 103,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 103,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 103,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 103,
                'char' => 51,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fetch',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'parameter',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 104,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'arguments',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 104,
                        'char' => 42,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'position',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 104,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 104,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 104,
                    'char' => 53,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameter',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 105,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 106,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 107,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 109,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 109,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 110,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a parameter in a specific position
     *
     * @return array
     *',
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 88,
          'last-line' => 114,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isResolved',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 117,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'resolved',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 117,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 117,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 118,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns true if the service was resolved
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
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 116,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 116,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 115,
          'last-line' => 122,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isShared',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 125,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'shared',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 125,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 125,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 126,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check whether the service is shared or not
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
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 124,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 124,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 123,
          'last-line' => 132,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'resolve',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'parameters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 133,
                'char' => 46,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 133,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 133,
                'char' => 70,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 133,
                'char' => 78,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 133,
              'char' => 78,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'bool',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'found',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 135,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 136,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'shared',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 136,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 136,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'sharedInstance',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 136,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'instance',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 136,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'builder',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 136,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 138,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'shared',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 138,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'shared',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 138,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 138,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 138,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 143,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'shared',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 143,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'sharedInstance',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 144,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sharedInstance',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 144,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 144,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 144,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 145,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'sharedInstance',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 145,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 145,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 145,
                    'char' => 40,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'sharedInstance',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 146,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 147,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 148,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 150,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'found',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 150,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 150,
                  'char' => 25,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'instance',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 151,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 151,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 153,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 153,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 153,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 153,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 153,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 154,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'typeof',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 154,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 154,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 154,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 154,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'class_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'definition',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 159,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 159,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 159,
                    'char' => 41,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'typeof',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameters',
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 160,
                              'char' => 39,
                            ),
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 160,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'array',
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 160,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 160,
                          'char' => 48,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'count',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 160,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 160,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 160,
                          'char' => 68,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 160,
                        'char' => 68,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'create_instance_params',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'definition',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 162,
                                      'char' => 35,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 162,
                                    'char' => 35,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameters',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 164,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 164,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 164,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 164,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 165,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'create_instance',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'definition',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 166,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 166,
                                    'char' => 62,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 166,
                                'char' => 63,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 166,
                              'char' => 63,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 167,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 168,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'variable',
                          'operator' => 'assign',
                          'variable' => 'found',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'false',
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 169,
                            'char' => 34,
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 169,
                          'char' => 34,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 170,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 171,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'definition',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 177,
                        'char' => 35,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 177,
                      'char' => 35,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 177,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 177,
                    'char' => 44,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'instanceof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'definition',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 178,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'Closure',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 178,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 178,
                        'char' => 50,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 183,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 183,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'object',
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 183,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 183,
                            'char' => 51,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'definition',
                                  'expr' => 
                                  array (
                                    'type' => 'scall',
                                    'dynamic-class' => 0,
                                    'class' => 'Closure',
                                    'dynamic' => 0,
                                    'name' => 'bind',
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'definition',
                                          'file' => '/app/phalcon/Di/Service.zep',
                                          'line' => 184,
                                          'char' => 66,
                                        ),
                                        'file' => '/app/phalcon/Di/Service.zep',
                                        'line' => 184,
                                        'char' => 66,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'container',
                                          'file' => '/app/phalcon/Di/Service.zep',
                                          'line' => 184,
                                          'char' => 77,
                                        ),
                                        'file' => '/app/phalcon/Di/Service.zep',
                                        'line' => 184,
                                        'char' => 77,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 184,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Di/Service.zep',
                                  'line' => 184,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 185,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 187,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'typeof',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'parameters',
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 187,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 187,
                              'char' => 43,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'array',
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 187,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 187,
                            'char' => 51,
                          ),
                          'statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'instance',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'call_user_func_array',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'definition',
                                          'file' => '/app/phalcon/Di/Service.zep',
                                          'line' => 189,
                                          'char' => 39,
                                        ),
                                        'file' => '/app/phalcon/Di/Service.zep',
                                        'line' => 189,
                                        'char' => 39,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'parameters',
                                          'file' => '/app/phalcon/Di/Service.zep',
                                          'line' => 191,
                                          'char' => 25,
                                        ),
                                        'file' => '/app/phalcon/Di/Service.zep',
                                        'line' => 191,
                                        'char' => 25,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 191,
                                    'char' => 26,
                                  ),
                                  'file' => '/app/phalcon/Di/Service.zep',
                                  'line' => 191,
                                  'char' => 26,
                                ),
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 192,
                              'char' => 21,
                            ),
                          ),
                          'else_statements' => 
                          array (
                            0 => 
                            array (
                              'type' => 'let',
                              'assignments' => 
                              array (
                                0 => 
                                array (
                                  'assign-type' => 'variable',
                                  'operator' => 'assign',
                                  'variable' => 'instance',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'call_user_func',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'definition',
                                          'file' => '/app/phalcon/Di/Service.zep',
                                          'line' => 193,
                                          'char' => 65,
                                        ),
                                        'file' => '/app/phalcon/Di/Service.zep',
                                        'line' => 193,
                                        'char' => 65,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 193,
                                    'char' => 66,
                                  ),
                                  'file' => '/app/phalcon/Di/Service.zep',
                                  'line' => 193,
                                  'char' => 66,
                                ),
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 194,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 195,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 196,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 196,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 197,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 198,
                      'char' => 13,
                    ),
                  ),
                  'else_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'definition',
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 202,
                            'char' => 39,
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 202,
                          'char' => 39,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 202,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 202,
                        'char' => 47,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'builder',
                              'expr' => 
                              array (
                                'type' => 'new',
                                'class' => 'Builder',
                                'dynamic' => 0,
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 203,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 203,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'instance',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'builder',
                                  'file' => '/app/phalcon/Di/Service.zep',
                                  'line' => 204,
                                  'char' => 44,
                                ),
                                'name' => 'build',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'container',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 205,
                                      'char' => 38,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 205,
                                    'char' => 38,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'definition',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 206,
                                      'char' => 39,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 206,
                                    'char' => 39,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'parameters',
                                      'file' => '/app/phalcon/Di/Service.zep',
                                      'line' => 208,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Di/Service.zep',
                                    'line' => 208,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 208,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 208,
                              'char' => 26,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 209,
                          'char' => 17,
                        ),
                      ),
                      'else_statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'found',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Di/Service.zep',
                                'line' => 210,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 210,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 211,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 212,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 213,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 218,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'found',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 218,
                    'char' => 29,
                  ),
                  'right' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 218,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 218,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 218,
                'char' => 37,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'ServiceResolutionException',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 219,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 220,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 225,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'shared',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 225,
                'char' => 19,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'sharedInstance',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'instance',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 226,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 226,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 227,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 229,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'resolved',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 229,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 229,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 231,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'instance',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 231,
                'char' => 24,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 232,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Resolves the service
     *
     * @param array parameters
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'variable',
                'mandatory' => 0,
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 133,
          'last-line' => 236,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefinition',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'definition',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 237,
              'char' => 49,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 239,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 239,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 240,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the service definition
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 238,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 237,
          'last-line' => 244,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setParameter',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'position',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 245,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'parameter',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 245,
              'char' => 64,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 247,
                  'char' => 23,
                ),
                1 => 
                array (
                  'variable' => 'arguments',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 247,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 249,
              'char' => 11,
            ),
            1 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 249,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 249,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 249,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 249,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 251,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'definition',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 251,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 251,
                    'char' => 40,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 251,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 251,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 251,
                'char' => 48,
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
                          'value' => 'Definition must be an array to update its parameters',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 254,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 254,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 254,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 255,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 260,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'fetch',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'arguments',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 260,
                  'char' => 51,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 260,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 260,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 260,
                  'char' => 51,
                ),
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 260,
                'char' => 51,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'array-index',
                      'operator' => 'assign',
                      'variable' => 'arguments',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'variable',
                          'value' => 'position',
                          'file' => '/app/phalcon/Di/Service.zep',
                          'line' => 261,
                          'char' => 35,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'parameter',
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 261,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 261,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 262,
                  'char' => 9,
                ),
              ),
              'else_statements' => 
              array (
                0 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'arguments',
                      'expr' => 
                      array (
                        'type' => 'array',
                        'left' => 
                        array (
                          0 => 
                          array (
                            'key' => 
                            array (
                              'type' => 'variable',
                              'value' => 'position',
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 263,
                              'char' => 38,
                            ),
                            'value' => 
                            array (
                              'type' => 'variable',
                              'value' => 'parameter',
                              'file' => '/app/phalcon/Di/Service.zep',
                              'line' => 263,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Di/Service.zep',
                            'line' => 263,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Di/Service.zep',
                        'line' => 263,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 263,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 264,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 269,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'array-index',
                  'operator' => 'assign',
                  'variable' => 'definition',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'string',
                      'value' => 'arguments',
                      'file' => '/app/phalcon/Di/Service.zep',
                      'line' => 269,
                      'char' => 33,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'arguments',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 269,
                    'char' => 46,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 269,
                  'char' => 46,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 274,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'definition',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 274,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 274,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 276,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 276,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 277,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes a parameter in the definition without resolve the service
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
                  'value' => 'ServiceInterface',
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 246,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Di/Service.zep',
                'line' => 246,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 246,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 245,
          'last-line' => 281,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setShared',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'shared',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 282,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'shared',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'shared',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 284,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 284,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 285,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the service is shared or not
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 283,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 282,
          'last-line' => 289,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSharedInstance',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'sharedInstance',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 290,
              'char' => 57,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'sharedInstance',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'sharedInstance',
                    'file' => '/app/phalcon/Di/Service.zep',
                    'line' => 292,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Di/Service.zep',
                  'line' => 292,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Di/Service.zep',
              'line' => 293,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets/Resets the shared instance related to the service
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Di/Service.zep',
            'line' => 291,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Di/Service.zep',
          'line' => 290,
          'last-line' => 294,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Di/Service.zep',
      'line' => 32,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Di/Service.zep',
    'line' => 32,
    'char' => 5,
  ),
);