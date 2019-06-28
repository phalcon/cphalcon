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
    'file' => '/app/phalcon/Container.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Container.zep',
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
        'name' => 'Psr\\Container\\ContainerInterface',
        'file' => '/app/phalcon/Container.zep',
        'line' => 13,
        'char' => 37,
      ),
    ),
    'file' => '/app/phalcon/Container.zep',
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
        'file' => '/app/phalcon/Container.zep',
        'line' => 14,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Container.zep',
    'line' => 18,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * PSR-11 Wrapper for `Phalcon\\Di`
 *',
    'file' => '/app/phalcon/Container.zep',
    'line' => 19,
    'char' => 5,
  ),
  5 => 
  array (
    'type' => 'class',
    'name' => 'Container',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'ContainerInterface',
        'file' => '/app/phalcon/Container.zep',
        'line' => 20,
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
          'name' => 'container',
          'docblock' => '**
     * @var <DiInterface>
     *',
          'file' => '/app/phalcon/Container.zep',
          'line' => 28,
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
              'name' => 'container',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'DiInterface',
                'file' => '/app/phalcon/Container.zep',
                'line' => 29,
                'char' => 55,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Container.zep',
              'line' => 29,
              'char' => 56,
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
                  'property' => 'container',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 31,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Container.zep',
                  'line' => 31,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Container.zep',
              'line' => 32,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Container constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Container.zep',
            'line' => 30,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Container.zep',
          'line' => 29,
          'last-line' => 36,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Container.zep',
              'line' => 37,
              'char' => 33,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 39,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 39,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Container.zep',
                  'line' => 39,
                  'char' => 32,
                ),
                'name' => 'getService',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Container.zep',
                      'line' => 39,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 39,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Container.zep',
                'line' => 39,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Container.zep',
              'line' => 40,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return the service
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
                'file' => '/app/phalcon/Container.zep',
                'line' => 38,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Container.zep',
            'line' => 38,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Container.zep',
          'line' => 37,
          'last-line' => 44,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'has',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'name',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Container.zep',
              'line' => 45,
              'char' => 33,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 47,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'container',
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 47,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Container.zep',
                  'line' => 47,
                  'char' => 32,
                ),
                'name' => 'has',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Container.zep',
                      'line' => 47,
                      'char' => 41,
                    ),
                    'file' => '/app/phalcon/Container.zep',
                    'line' => 47,
                    'char' => 41,
                  ),
                ),
                'file' => '/app/phalcon/Container.zep',
                'line' => 47,
                'char' => 42,
              ),
              'file' => '/app/phalcon/Container.zep',
              'line' => 48,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Whether a service exists or not in the container
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
                'file' => '/app/phalcon/Container.zep',
                'line' => 46,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Container.zep',
            'line' => 46,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Container.zep',
          'line' => 45,
          'last-line' => 49,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Container.zep',
      'line' => 19,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Container.zep',
    'line' => 19,
    'char' => 5,
  ),
);