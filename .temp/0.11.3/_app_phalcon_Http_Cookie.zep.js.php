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
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Http',
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\DiInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\CryptInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 14,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 15,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\Filter\\FilterInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 16,
        'char' => 35,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\Http\\Response\\Exception',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 17,
        'char' => 36,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
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
        'name' => 'Phalcon\\Http\\Cookie\\Exception',
        'alias' => 'CookieException',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 18,
        'char' => 53,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 19,
    'char' => 3,
  ),
  8 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Crypt\\Mismatch',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 19,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 20,
    'char' => 3,
  ),
  9 => 
  array (
    'type' => 'use',
    'aliases' => 
    array (
      0 => 
      array (
        'name' => 'Phalcon\\Session\\ManagerInterface',
        'alias' => 'SessionManagerInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 20,
        'char' => 64,
      ),
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 24,
    'char' => 2,
  ),
  10 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Provide OO wrappers to manage a HTTP cookie.
 *',
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 25,
    'char' => 5,
  ),
  11 => 
  array (
    'type' => 'class',
    'name' => 'Cookie',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CookieInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 25,
        'char' => 40,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Http/Cookie.zep',
        'line' => 26,
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
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 29,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'domain',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 31,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'expire',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 33,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'filter',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 35,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'httpOnly',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 37,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'name',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 39,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'path',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 41,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'read',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 41,
            'char' => 27,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 43,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'restored',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 43,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 45,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'secure',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 50,
          'char' => 6,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'signKey',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 51,
            'char' => 29,
          ),
          'docblock' => '**
     * The cookie\'s sign key.
     * @var string|null
     *',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 53,
          'char' => 13,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'useEncryption',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'false',
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 53,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 55,
          'char' => 13,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'value',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 59,
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
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 61,
              'char' => 21,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 62,
                'char' => 25,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 62,
              'char' => 25,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'expire',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 63,
                'char' => 23,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 63,
              'char' => 23,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'string',
                'value' => '/',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 64,
                'char' => 24,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 64,
              'char' => 24,
            ),
            4 => 
            array (
              'type' => 'parameter',
              'name' => 'secure',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 65,
                'char' => 27,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 65,
              'char' => 27,
            ),
            5 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 66,
                'char' => 29,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 66,
              'char' => 29,
            ),
            6 => 
            array (
              'type' => 'parameter',
              'name' => 'httpOnly',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 68,
                'char' => 5,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 68,
              'char' => 5,
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
                  'property' => 'name',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'name',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 69,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 69,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 71,
              'char' => 10,
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
                  'value' => 'value',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 71,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 71,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 71,
                'char' => 27,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 72,
                      'char' => 18,
                    ),
                    'name' => 'setValue',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'value',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 72,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 72,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 72,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 73,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 75,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'expire',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'expire',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 75,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 75,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 77,
              'char' => 11,
            ),
            3 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 77,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 77,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 79,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'secure',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'secure',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 79,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 79,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 81,
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
                  'property' => 'domain',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'domain',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 81,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 81,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 83,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'httpOnly',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'httpOnly',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 83,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 83,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 84,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Http\\Cookie constructor.
     *',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 60,
          'last-line' => 88,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => '__toString',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'cast',
                'left' => 'string',
                'right' => 
                array (
                  'type' => 'mcall',
                  'variable' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 91,
                    'char' => 30,
                  ),
                  'name' => 'getValue',
                  'call-type' => 1,
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 91,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 91,
                'char' => 41,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 92,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Magic __toString method converts the cookie\'s value to string
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 90,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 90,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 89,
          'last-line' => 96,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'delete',
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'domain',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 25,
                ),
                2 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 31,
                ),
                3 => 
                array (
                  'variable' => 'secure',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 39,
                ),
                4 => 
                array (
                  'variable' => 'httpOnly',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 49,
                ),
                5 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 60,
                ),
                6 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 99,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 101,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 101,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 101,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 101,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 101,
                  'char' => 34,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'domain',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 102,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 102,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 102,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 102,
                  'char' => 36,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 103,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 103,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 103,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 103,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'secure',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 104,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'secure',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 104,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 104,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 104,
                  'char' => 36,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'httpOnly',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 105,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpOnly',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 105,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 105,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 105,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 107,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 107,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 107,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 107,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 107,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 107,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 107,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 109,
              'char' => 10,
            ),
            3 => 
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
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 109,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 109,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'object',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 109,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 109,
                'char' => 39,
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
                      'variable' => 'session',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SessionManagerInterface',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 110,
                          'char' => 82,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 110,
                            'char' => 63,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'session',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 110,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 110,
                              'char' => 81,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 110,
                          'char' => 82,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 110,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 110,
                      'char' => 82,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 112,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 112,
                      'char' => 24,
                    ),
                    'name' => 'exists',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 112,
                    'char' => 34,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'session',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 113,
                          'char' => 25,
                        ),
                        'name' => 'remove',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '_PHCOOKIE_',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 113,
                                'char' => 44,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 113,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 113,
                              'char' => 50,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 113,
                            'char' => 50,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 113,
                        'char' => 51,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 114,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 115,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 117,
              'char' => 11,
            ),
            4 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'value',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 117,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 117,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 119,
              'char' => 17,
            ),
            5 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'setcookie',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 120,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 120,
                    'char' => 17,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 121,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 121,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'sub',
                      'left' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'time',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 122,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '691200',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 122,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 122,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 122,
                    'char' => 28,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 123,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 123,
                    'char' => 17,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 124,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 124,
                    'char' => 19,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'secure',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 125,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 125,
                    'char' => 19,
                  ),
                  6 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpOnly',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 127,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 127,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 127,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 128,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Deletes the cookie by setting an expire time in the past
     *',
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 97,
          'last-line' => 132,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDI',
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
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 135,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 135,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 135,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 136,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the internal dependency injector
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
                  'value' => 'DiInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 134,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 134,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 134,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 133,
          'last-line' => 140,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDomain',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 143,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 143,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 143,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 143,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 144,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 144,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 145,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 147,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 147,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'domain',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 147,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 147,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 148,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the domain that the cookie is available to
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 142,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 142,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 141,
          'last-line' => 152,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getExpiration',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 155,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 155,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 155,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 155,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 156,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 156,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 157,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 159,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 159,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'expire',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 159,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 159,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 160,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current expiration time
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 154,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 154,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 153,
          'last-line' => 164,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHttpOnly',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 167,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 167,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 167,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 167,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 168,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 168,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 169,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 171,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 171,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'httpOnly',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 171,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 171,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 172,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns if the cookie is accessible only through the HTTP protocol
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 166,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 166,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 165,
          'last-line' => 176,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getName',
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
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 179,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'name',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 179,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 179,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 180,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current cookie\'s name
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 178,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 178,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 177,
          'last-line' => 184,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getPath',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 187,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 187,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 187,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 187,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 188,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 188,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 189,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 191,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 191,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'path',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 191,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 191,
                'char' => 26,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 192,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current cookie\'s path
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 186,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 186,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 185,
          'last-line' => 197,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSecure',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 200,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 200,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 200,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 200,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 201,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 201,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 202,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 204,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 204,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'secure',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 204,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 204,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 205,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns whether the cookie must only be sent when the connection is
     * secure (HTTPS)
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 199,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 199,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 198,
          'last-line' => 209,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'filters',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 210,
                'char' => 48,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 210,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 210,
                'char' => 73,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 210,
              'char' => 73,
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'crypt',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 36,
                ),
                3 => 
                array (
                  'variable' => 'decryptedValue',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'filter',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 60,
                ),
                5 => 
                array (
                  'variable' => 'signKey',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 69,
                ),
                6 => 
                array (
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 212,
                  'char' => 75,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 214,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 214,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 214,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 214,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 214,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 215,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 215,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 216,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 218,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 218,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 218,
                  'char' => 29,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 219,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 219,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 219,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 219,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 221,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 221,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'read',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 221,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 221,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'false',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 221,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 221,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'fetch',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 222,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => '_COOKIE',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 222,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'name',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 222,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 222,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 222,
                      'char' => 44,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 222,
                    'char' => 44,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultValue',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 223,
                        'char' => 36,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 224,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 226,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 226,
                      'char' => 21,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'useEncryption',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 226,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 226,
                    'char' => 36,
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
                          'variable' => 'container',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'DiInterface',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 227,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 227,
                                'char' => 52,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 227,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 227,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 227,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 227,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 229,
                      'char' => 18,
                    ),
                    1 => 
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
                              'value' => 'container',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 229,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 229,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 229,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 229,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 229,
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
                                  'type' => 'scall',
                                  'dynamic-class' => 0,
                                  'class' => 'Exception',
                                  'dynamic' => 0,
                                  'name' => 'containerServiceNotFound',
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'the \'filter\' and \'crypt\' services',
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 233,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 233,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 234,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 234,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 234,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 235,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 237,
                      'char' => 19,
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
                          'variable' => 'crypt',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'CryptInterface',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 237,
                              'char' => 73,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 237,
                                'char' => 56,
                              ),
                              'name' => 'getShared',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'crypt',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 237,
                                    'char' => 72,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 237,
                                  'char' => 72,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 237,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 237,
                            'char' => 73,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 237,
                          'char' => 73,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 239,
                      'char' => 18,
                    ),
                    3 => 
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
                              'value' => 'crypt',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 239,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 239,
                            'char' => 43,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 239,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 239,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 239,
                        'char' => 52,
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
                                  'value' => 'A dependency which implements CryptInterface is required to use encryption',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 242,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 242,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 242,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 243,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 248,
                      'char' => 19,
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
                          'variable' => 'signKey',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 248,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'signKey',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 248,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 248,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 248,
                          'char' => 44,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 250,
                      'char' => 18,
                    ),
                    5 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'identical',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'signKey',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 250,
                            'char' => 37,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 250,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'string',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 250,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 250,
                        'char' => 46,
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
                              'variable' => 'decryptedValue',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'crypt',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 254,
                                  'char' => 48,
                                ),
                                'name' => 'decryptBase64',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 255,
                                      'char' => 30,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 255,
                                    'char' => 30,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'signKey',
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 257,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 257,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 257,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 257,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 258,
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
                              'variable' => 'decryptedValue',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'crypt',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 262,
                                  'char' => 48,
                                ),
                                'name' => 'decryptBase64',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'value',
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 262,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 262,
                                    'char' => 68,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 262,
                                'char' => 69,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 262,
                              'char' => 69,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 263,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 264,
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
                          'variable' => 'decryptedValue',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'value',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 265,
                            'char' => 43,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 265,
                          'char' => 43,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 266,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 271,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'value',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'decryptedValue',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 271,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 271,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 273,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-identical',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'filters',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 273,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 273,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 273,
                    'char' => 33,
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
                          'variable' => 'filter',
                          'expr' => 
                          array (
                            'type' => 'property-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 274,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filter',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 274,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 274,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 274,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 276,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'not-equals',
                        'left' => 
                        array (
                          'type' => 'typeof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'filter',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 276,
                            'char' => 35,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 276,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'object',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 276,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 276,
                        'char' => 44,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'identical',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 277,
                              'char' => 36,
                            ),
                            'right' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 277,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 277,
                            'char' => 43,
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
                                  'variable' => 'container',
                                  'expr' => 
                                  array (
                                    'type' => 'type-hint',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'DiInterface',
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 278,
                                      'char' => 70,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'property-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 278,
                                        'char' => 60,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'container',
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 278,
                                        'char' => 70,
                                      ),
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 278,
                                      'char' => 70,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 278,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 278,
                                  'char' => 70,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 280,
                              'char' => 26,
                            ),
                            1 => 
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
                                      'value' => 'container',
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 280,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 280,
                                    'char' => 55,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'object',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 280,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 280,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 280,
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
                                          'type' => 'scall',
                                          'dynamic-class' => 0,
                                          'class' => 'Exception',
                                          'dynamic' => 0,
                                          'name' => 'containerServiceNotFound',
                                          'parameters' => 
                                          array (
                                            0 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'string',
                                                'value' => 'the \'filter\' service',
                                                'file' => '/app/phalcon/Http/Cookie.zep',
                                                'line' => 284,
                                                'char' => 33,
                                              ),
                                              'file' => '/app/phalcon/Http/Cookie.zep',
                                              'line' => 284,
                                              'char' => 33,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Http/Cookie.zep',
                                          'line' => 285,
                                          'char' => 29,
                                        ),
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 285,
                                        'char' => 29,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 285,
                                    'char' => 30,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 286,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 287,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 289,
                          'char' => 23,
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
                              'variable' => 'filter',
                              'expr' => 
                              array (
                                'type' => 'type-hint',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'FilterInterface',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 289,
                                  'char' => 80,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'container',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 289,
                                    'char' => 62,
                                  ),
                                  'name' => 'getShared',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => 'filter',
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 289,
                                        'char' => 79,
                                      ),
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 289,
                                      'char' => 79,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 289,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 289,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 289,
                              'char' => 80,
                            ),
                            1 => 
                            array (
                              'assign-type' => 'object-property',
                              'operator' => 'assign',
                              'variable' => 'this',
                              'property' => 'filter',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'filter',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 290,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 290,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 291,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 293,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'filter',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 293,
                          'char' => 31,
                        ),
                        'name' => 'sanitize',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decryptedValue',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 293,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 293,
                            'char' => 55,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'filters',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 293,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 293,
                            'char' => 64,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 293,
                        'char' => 65,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 294,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 299,
                  'char' => 18,
                ),
                4 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'decryptedValue',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 299,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 300,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 302,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 302,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'value',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 302,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 302,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 303,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the cookie\'s value.
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 211,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 211,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 210,
          'last-line' => 307,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isUsingEncryption',
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
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 310,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'useEncryption',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 310,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 310,
                'char' => 35,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 311,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the cookie is using implicit encryption
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 309,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 309,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 308,
          'last-line' => 319,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'restore',
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
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'expire',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'domain',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 38,
                ),
                3 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 44,
                ),
                4 => 
                array (
                  'variable' => 'secure',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 52,
                ),
                5 => 
                array (
                  'variable' => 'httpOnly',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 62,
                ),
                6 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 322,
                  'char' => 71,
                ),
                7 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 323,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 325,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 325,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 325,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 325,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 325,
                'char' => 28,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 326,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 326,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 326,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 326,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 328,
                  'char' => 14,
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
                        'value' => 'container',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 328,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 328,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 328,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 328,
                    'char' => 43,
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
                          'variable' => 'session',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'container',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 329,
                              'char' => 41,
                            ),
                            'name' => 'getShared',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'session',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 329,
                                  'char' => 59,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 329,
                                'char' => 59,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 329,
                            'char' => 60,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 329,
                          'char' => 60,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 331,
                      'char' => 18,
                    ),
                    1 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'session',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 331,
                          'char' => 28,
                        ),
                        'name' => 'exists',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 331,
                        'char' => 38,
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
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'session',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 332,
                                  'char' => 46,
                                ),
                                'name' => 'get',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '_PHCOOKIE_',
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 333,
                                        'char' => 36,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'property-access',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'this',
                                          'file' => '/app/phalcon/Http/Cookie.zep',
                                          'line' => 333,
                                          'char' => 43,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'name',
                                          'file' => '/app/phalcon/Http/Cookie.zep',
                                          'line' => 334,
                                          'char' => 21,
                                        ),
                                        'file' => '/app/phalcon/Http/Cookie.zep',
                                        'line' => 334,
                                        'char' => 21,
                                      ),
                                      'file' => '/app/phalcon/Http/Cookie.zep',
                                      'line' => 334,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 334,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 334,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 334,
                              'char' => 22,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 336,
                          'char' => 22,
                        ),
                        1 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'expire',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 336,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 336,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'expire',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 336,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 336,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 336,
                            'char' => 57,
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
                                  'property' => 'expire',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'expire',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 337,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 337,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 338,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 340,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'domain',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 340,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 340,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'domain',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 340,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 340,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 340,
                            'char' => 57,
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
                                  'property' => 'domain',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'domain',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 341,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 341,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 342,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 344,
                          'char' => 22,
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
                              'value' => 'path',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 344,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 344,
                                'char' => 46,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'path',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 344,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 344,
                              'char' => 53,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 344,
                            'char' => 53,
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
                                  'property' => 'path',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'path',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 345,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 345,
                                  'char' => 46,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 346,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 348,
                          'char' => 22,
                        ),
                        4 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'secure',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 348,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 348,
                                'char' => 48,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'secure',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 348,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 348,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 348,
                            'char' => 57,
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
                                  'property' => 'secure',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'secure',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 349,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 349,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 350,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 352,
                          'char' => 22,
                        ),
                        5 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'fetch',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'httpOnly',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 352,
                              'char' => 61,
                            ),
                            'right' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'definition',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 352,
                                'char' => 50,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => 'httpOnly',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 352,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 352,
                              'char' => 61,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 352,
                            'char' => 61,
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
                                  'property' => 'httpOnly',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'httpOnly',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 353,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 353,
                                  'char' => 54,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 354,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 355,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 356,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 358,
                  'char' => 15,
                ),
                2 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'restored',
                      'expr' => 
                      array (
                        'type' => 'bool',
                        'value' => 'true',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 358,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 358,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 359,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 361,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 361,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 362,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Reads the cookie-related info from the SESSION to restore the cookie as
     * it was set.
     *
     * This method is automatically called internally so normally you don\'t
     * need to call it.
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 321,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 321,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 321,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 320,
          'last-line' => 368,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'send',
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
                  'variable' => 'name',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 17,
                ),
                1 => 
                array (
                  'variable' => 'value',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 24,
                ),
                2 => 
                array (
                  'variable' => 'expire',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 32,
                ),
                3 => 
                array (
                  'variable' => 'domain',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 40,
                ),
                4 => 
                array (
                  'variable' => 'path',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 46,
                ),
                5 => 
                array (
                  'variable' => 'secure',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 54,
                ),
                6 => 
                array (
                  'variable' => 'httpOnly',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 64,
                ),
                7 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 371,
                  'char' => 75,
                ),
                8 => 
                array (
                  'variable' => 'definition',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 372,
                  'char' => 23,
                ),
                9 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 372,
                  'char' => 32,
                ),
                10 => 
                array (
                  'variable' => 'crypt',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 372,
                  'char' => 39,
                ),
                11 => 
                array (
                  'variable' => 'encryptValue',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 372,
                  'char' => 53,
                ),
                12 => 
                array (
                  'variable' => 'signKey',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 372,
                  'char' => 62,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 374,
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
                  'variable' => 'name',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 374,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 374,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 374,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 374,
                  'char' => 30,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'value',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 375,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 375,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 375,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 375,
                  'char' => 32,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'expire',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 376,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expire',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 376,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 376,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 376,
                  'char' => 34,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'domain',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 377,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 377,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 377,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 377,
                  'char' => 34,
                ),
                4 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'path',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 378,
                      'char' => 25,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 378,
                      'char' => 30,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 378,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 378,
                  'char' => 30,
                ),
                5 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'secure',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 379,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'secure',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 379,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 379,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 379,
                  'char' => 34,
                ),
                6 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'httpOnly',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 380,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpOnly',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 380,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 380,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 380,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 382,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 382,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'container',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 382,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 382,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 382,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 384,
              'char' => 10,
            ),
            3 => 
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
                      'value' => 'container',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 384,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 384,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 384,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 384,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 384,
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
                          'type' => 'scall',
                          'dynamic-class' => 0,
                          'class' => 'Exception',
                          'dynamic' => 0,
                          'name' => 'containerServiceNotFound',
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'the \'session\' service',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 386,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 386,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 387,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 387,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 387,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 388,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 390,
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
                  'variable' => 'definition',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 390,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 390,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 392,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'expire',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 392,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 392,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 392,
                'char' => 24,
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
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'expire',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 393,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'expire',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 393,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 393,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 394,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 396,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 396,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 396,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 396,
                'char' => 24,
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
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'path',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 397,
                          'char' => 32,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'path',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 397,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 397,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 398,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 400,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'domain',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 400,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 400,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 400,
                'char' => 26,
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
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'domain',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 401,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'domain',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 401,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 401,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 402,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 404,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'secure',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 404,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 404,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 404,
                'char' => 26,
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
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'secure',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 405,
                          'char' => 34,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'secure',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 405,
                        'char' => 44,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 405,
                      'char' => 44,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 406,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 408,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'httpOnly',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 408,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 408,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 408,
                'char' => 28,
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
                      'variable' => 'definition',
                      'index-expr' => 
                      array (
                        0 => 
                        array (
                          'type' => 'string',
                          'value' => 'httpOnly',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 409,
                          'char' => 36,
                        ),
                      ),
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'httpOnly',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 409,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 409,
                      'char' => 48,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 410,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 415,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
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
                      'value' => 'definition',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 415,
                      'char' => 28,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 415,
                    'char' => 28,
                  ),
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 415,
                'char' => 30,
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
                      'variable' => 'session',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SessionManagerInterface',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 416,
                          'char' => 82,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 416,
                            'char' => 63,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'session',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 416,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 416,
                              'char' => 81,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 416,
                          'char' => 82,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 416,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 416,
                      'char' => 82,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 418,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 418,
                      'char' => 24,
                    ),
                    'name' => 'exists',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 418,
                    'char' => 34,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'mcall',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'session',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 419,
                          'char' => 25,
                        ),
                        'name' => 'set',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '_PHCOOKIE_',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 420,
                                'char' => 32,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'name',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 420,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 420,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 420,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'definition',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 422,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 422,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 422,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 423,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 424,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 426,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 426,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'useEncryption',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 426,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 426,
                  'char' => 33,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'value',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 426,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 426,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 426,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 426,
                'char' => 48,
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
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'typeof',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 427,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 427,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 427,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 427,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 427,
                    'char' => 52,
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
                              'type' => 'scall',
                              'dynamic-class' => 0,
                              'class' => 'Exception',
                              'dynamic' => 0,
                              'name' => 'containerServiceNotFound',
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'the \'filter\' service',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 431,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 431,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 432,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 432,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 432,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 433,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 435,
                  'char' => 15,
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
                      'variable' => 'crypt',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'CryptInterface',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 435,
                          'char' => 69,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 435,
                            'char' => 52,
                          ),
                          'name' => 'getShared',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'crypt',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 435,
                                'char' => 68,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 435,
                              'char' => 68,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 435,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 435,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 435,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 437,
                  'char' => 14,
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
                          'value' => 'crypt',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 437,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 437,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 437,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 437,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 437,
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
                              'value' => 'A dependency which implements CryptInterface is required to use encryption',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 440,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 440,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 440,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 441,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 447,
                  'char' => 15,
                ),
                3 => 
                array (
                  'type' => 'let',
                  'assignments' => 
                  array (
                    0 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'signKey',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 447,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'signKey',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 447,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 447,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 447,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 449,
                  'char' => 14,
                ),
                4 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'identical',
                    'left' => 
                    array (
                      'type' => 'typeof',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'signKey',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 449,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 449,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'string',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 449,
                      'char' => 42,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 449,
                    'char' => 42,
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
                          'variable' => 'encryptValue',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'crypt',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 450,
                              'char' => 42,
                            ),
                            'name' => 'encryptBase64',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'cast',
                                  'left' => 'string',
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 451,
                                    'char' => 35,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 451,
                                  'char' => 35,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 451,
                                'char' => 35,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'signKey',
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 453,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 453,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 453,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 453,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 454,
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
                          'variable' => 'encryptValue',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'crypt',
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 455,
                              'char' => 42,
                            ),
                            'name' => 'encryptBase64',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'cast',
                                  'left' => 'string',
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'value',
                                    'file' => '/app/phalcon/Http/Cookie.zep',
                                    'line' => 457,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Http/Cookie.zep',
                                  'line' => 457,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 457,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Http/Cookie.zep',
                            'line' => 457,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 457,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 458,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 459,
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
                      'variable' => 'encryptValue',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'value',
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 460,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 460,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 461,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 466,
              'char' => 17,
            ),
            12 => 
            array (
              'type' => 'fcall',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'setcookie',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'name',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 23,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 23,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'encryptValue',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 37,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'expire',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 45,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'path',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 51,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 51,
                  ),
                  4 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'domain',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 59,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 59,
                  ),
                  5 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'secure',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 67,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 67,
                  ),
                  6 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'httpOnly',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 466,
                      'char' => 77,
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 466,
                    'char' => 77,
                  ),
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 466,
                'char' => 78,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 468,
              'char' => 14,
            ),
            13 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 468,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 469,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sends the cookie to the HTTP client.
     *
     * Stores the cookie definition in session.
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 370,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 369,
          'last-line' => 473,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDI',
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
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 474,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 474,
              'char' => 50,
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
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 476,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 476,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 477,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the dependency injector
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 475,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 474,
          'last-line' => 481,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDomain',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'domain',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 482,
              'char' => 45,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 484,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 484,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 484,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 484,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 485,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 485,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 486,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 488,
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
                  'property' => 'domain',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'domain',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 488,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 488,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 490,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 490,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 491,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the domain that the cookie is available to
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 483,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 483,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 483,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 482,
          'last-line' => 495,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setExpiration',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'expire',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 496,
              'char' => 45,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 498,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 498,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 498,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 498,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 499,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 499,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 500,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 502,
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
                  'property' => 'expire',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'expire',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 502,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 502,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 504,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 504,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 505,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s expiration time
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 497,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 497,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 497,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 496,
          'last-line' => 509,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHttpOnly',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'httpOnly',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 510,
              'char' => 46,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 512,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 512,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 512,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 512,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 513,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 513,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 514,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 516,
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
                  'property' => 'httpOnly',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'httpOnly',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 516,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 516,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 518,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 518,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 519,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie is accessible only through the HTTP protocol
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 511,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 511,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 511,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 510,
          'last-line' => 523,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 524,
              'char' => 41,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 526,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 526,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 526,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 526,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 527,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 527,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 528,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 530,
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
                  'property' => 'path',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'path',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 530,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 530,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 532,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 532,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 533,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s expiration time
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 525,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 525,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 525,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 524,
          'last-line' => 537,
          'char' => 19,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSecure',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'secure',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 538,
              'char' => 42,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 540,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'restored',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 540,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 540,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 540,
                'char' => 28,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 541,
                      'char' => 18,
                    ),
                    'name' => 'restore',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 541,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 542,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 544,
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
                  'property' => 'secure',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'secure',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 544,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 544,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 546,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 546,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 547,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie must only be sent when the connection is secure (HTTPS)
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 539,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 539,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 539,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 538,
          'last-line' => 559,
          'char' => 19,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setSignKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'signKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 560,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 560,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'signKey',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 562,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 562,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 562,
                'char' => 29,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Http/Cookie.zep',
                      'line' => 563,
                      'char' => 18,
                    ),
                    'name' => 'assertSignKeyIsLongEnough',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'signKey',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 563,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 563,
                        'char' => 52,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 563,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 564,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 566,
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
                  'property' => 'signKey',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'signKey',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 566,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 566,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 568,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 568,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 569,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s sign key.
     *
     * The `$signKey\' MUST be at least 32 characters long
     * and generated using a cryptographically secure pseudo random generator.
     *
     * Use NULL to disable cookie signing.
     *
     * @see \\Phalcon\\Security\\Random
     * @throws \\Phalcon\\Http\\Cookie\\Exception
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 561,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 561,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 561,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 560,
          'last-line' => 575,
          'char' => 19,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setValue',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'value',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 576,
              'char' => 35,
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
                  'property' => 'value',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'value',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 578,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 578,
                  'char' => 32,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'read',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'true',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 579,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 579,
                  'char' => 30,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 581,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 581,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 582,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cookie\'s value
     *
     * @param string value
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 577,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 577,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 577,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 576,
          'last-line' => 586,
          'char' => 19,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useEncryption',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'useEncryption',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 587,
              'char' => 53,
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
                  'property' => 'useEncryption',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'useEncryption',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 589,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 589,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 591,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 591,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 592,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the cookie must be encrypted/decrypted automatically
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
                  'value' => 'CookieInterface',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 588,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 588,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 588,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 587,
          'last-line' => 598,
          'char' => 19,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'assertSignKeyIsLongEnough',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'signKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 599,
              'char' => 65,
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
                  'variable' => 'length',
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 601,
                  'char' => 19,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 603,
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
                  'variable' => 'length',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_strlen',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'signKey',
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 603,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 603,
                        'char' => 39,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 603,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 603,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 605,
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
                  'type' => 'less',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'length',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 605,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '32',
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 605,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 605,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Http/Cookie.zep',
                'line' => 605,
                'char' => 33,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'throw',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'CookieException',
                    'dynamic' => 0,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'sprintf',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'The cookie\'s key should be at least 32 characters long. Current length is %d.',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 608,
                                'char' => 98,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 608,
                              'char' => 98,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'length',
                                'file' => '/app/phalcon/Http/Cookie.zep',
                                'line' => 610,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Http/Cookie.zep',
                              'line' => 610,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Http/Cookie.zep',
                          'line' => 611,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Http/Cookie.zep',
                        'line' => 611,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Http/Cookie.zep',
                    'line' => 611,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Http/Cookie.zep',
                  'line' => 612,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Http/Cookie.zep',
              'line' => 613,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assert the cookie\'s key is enough long.
     *
     * @throws \\Phalcon\\Http\\Cookie\\Exception
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Http/Cookie.zep',
            'line' => 600,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Http/Cookie.zep',
          'line' => 599,
          'last-line' => 614,
          'char' => 22,
        ),
      ),
      'file' => '/app/phalcon/Http/Cookie.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Http/Cookie.zep',
    'line' => 25,
    'char' => 5,
  ),
);