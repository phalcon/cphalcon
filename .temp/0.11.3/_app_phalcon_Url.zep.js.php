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
    'file' => '/app/phalcon/Url.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Url.zep',
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
        'file' => '/app/phalcon/Url.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
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
        'name' => 'Phalcon\\UrlInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 14,
        'char' => 25,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
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
        'name' => 'Phalcon\\Url\\Exception',
        'file' => '/app/phalcon/Url.zep',
        'line' => 15,
        'char' => 26,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
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
        'name' => 'Phalcon\\Mvc\\RouterInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 16,
        'char' => 32,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
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
        'name' => 'Phalcon\\Mvc\\Router\\RouteInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 17,
        'char' => 38,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 18,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Url.zep',
    'line' => 36,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This components helps in the generation of: URIs, URLs and Paths
 *
 *```php
 * // Generate a URL appending the URI to the base URI
 * echo $url->get("products/edit/1");
 *
 * // Generate a URL for a predefined route
 * echo $url->get(
 *     [
 *         "for"   => "blog-post",
 *         "title" => "some-cool-stuff",
 *         "year"  => "2012",
 *     ]
 * );
 *```
 *',
    'file' => '/app/phalcon/Url.zep',
    'line' => 37,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Url',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'UrlInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 37,
        'char' => 34,
      ),
      1 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Url.zep',
        'line' => 38,
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
          'name' => 'baseUri',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Url.zep',
            'line' => 42,
            'char' => 29,
          ),
          'docblock' => '**
     * @var null | string
     *',
          'file' => '/app/phalcon/Url.zep',
          'line' => 46,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'basePath',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Url.zep',
            'line' => 47,
            'char' => 30,
          ),
          'docblock' => '**
     * @var null | string
     *',
          'file' => '/app/phalcon/Url.zep',
          'line' => 51,
          'char' => 6,
        ),
        2 => 
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
          'file' => '/app/phalcon/Url.zep',
          'line' => 54,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'router',
          'file' => '/app/phalcon/Url.zep',
          'line' => 58,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'staticBaseUri',
          'default' => 
          array (
            'type' => 'null',
            'file' => '/app/phalcon/Url.zep',
            'line' => 59,
            'char' => 35,
          ),
          'docblock' => '**
     * @var null | string
     *',
          'file' => '/app/phalcon/Url.zep',
          'line' => 93,
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
          'name' => 'get',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 94,
                'char' => 39,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 94,
              'char' => 39,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'args',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 94,
                'char' => 56,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 94,
              'char' => 56,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'local',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 94,
                'char' => 75,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 94,
              'char' => 75,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'baseUri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 94,
                'char' => 95,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 94,
              'char' => 95,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'strUri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 96,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 97,
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
                  'variable' => 'router',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 97,
                  'char' => 19,
                ),
                1 => 
                array (
                  'variable' => 'container',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 97,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'routeName',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 97,
                  'char' => 41,
                ),
                3 => 
                array (
                  'variable' => 'route',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 97,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'queryString',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 97,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 99,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'local',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 99,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 99,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 99,
                'char' => 26,
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
                          'value' => 'uri',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 100,
                          'char' => 28,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 100,
                        'char' => 28,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 100,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 100,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'memstr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 100,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 100,
                              'char' => 51,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '//',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 100,
                                'char' => 55,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 100,
                              'char' => 55,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 100,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'memstr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 100,
                                'char' => 70,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 100,
                              'char' => 70,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => ':',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 100,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 100,
                              'char' => 73,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 100,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 100,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 100,
                      'char' => 76,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 100,
                    'char' => 76,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'preg_match',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '#^((//)|([a-z0-9]+://)|([a-z0-9]+:))#i',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 101,
                              'char' => 69,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 101,
                            'char' => 69,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 101,
                              'char' => 74,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 101,
                            'char' => 74,
                          ),
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 101,
                        'char' => 76,
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
                              'variable' => 'local',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'false',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 102,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 102,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 103,
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
                              'variable' => 'local',
                              'expr' => 
                              array (
                                'type' => 'bool',
                                'value' => 'true',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 104,
                                'char' => 37,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 104,
                              'char' => 37,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 105,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 106,
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
                          'variable' => 'local',
                          'expr' => 
                          array (
                            'type' => 'bool',
                            'value' => 'true',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 107,
                            'char' => 33,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 107,
                          'char' => 33,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 108,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 109,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 111,
              'char' => 10,
            ),
            3 => 
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
                    'value' => 'baseUri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 111,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 111,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'string',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 111,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 111,
                'char' => 37,
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
                      'variable' => 'baseUri',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 112,
                          'char' => 32,
                        ),
                        'name' => 'getBaseUri',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 112,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 112,
                      'char' => 45,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 113,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 115,
              'char' => 10,
            ),
            4 => 
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
                    'value' => 'uri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 115,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 115,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 115,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 115,
                'char' => 32,
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
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'fetch',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'routeName',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 116,
                          'char' => 52,
                        ),
                        'right' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'uri',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 116,
                            'char' => 46,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'for',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 116,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 116,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 116,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 116,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 116,
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
                              'value' => 'It\'s necessary to define the route name with the parameter \'for\'',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 119,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 119,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 119,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 120,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 122,
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
                      'variable' => 'router',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'RouterInterface',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 122,
                          'char' => 56,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 122,
                            'char' => 49,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'router',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 122,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 122,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 122,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 122,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 127,
                  'char' => 14,
                ),
                2 => 
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
                        'value' => 'router',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 127,
                        'char' => 31,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 127,
                      'char' => 31,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'object',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 127,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 127,
                    'char' => 40,
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
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 128,
                              'char' => 62,
                            ),
                            'right' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 128,
                                'char' => 52,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 128,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 128,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 128,
                            'char' => 62,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 128,
                          'char' => 62,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 130,
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
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 130,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 130,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'object',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 130,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 130,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 130,
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
                                        'value' => 'the \'router\' service',
                                        'file' => '/app/phalcon/Url.zep',
                                        'line' => 134,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Url.zep',
                                      'line' => 134,
                                      'char' => 25,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 135,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 135,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 135,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 136,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 138,
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
                          'variable' => 'router',
                          'expr' => 
                          array (
                            'type' => 'type-hint',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'RouterInterface',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 138,
                              'char' => 76,
                            ),
                            'right' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'container',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 138,
                                'char' => 58,
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
                                    'value' => 'router',
                                    'file' => '/app/phalcon/Url.zep',
                                    'line' => 138,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 138,
                                  'char' => 75,
                                ),
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 138,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 138,
                            'char' => 76,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 138,
                          'char' => 76,
                        ),
                        1 => 
                        array (
                          'assign-type' => 'object-property',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'router',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'router',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 139,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 139,
                          'char' => 42,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 140,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 145,
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
                      'variable' => 'route',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'RouteInterface',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 145,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'router',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 145,
                            'char' => 49,
                          ),
                          'name' => 'getRouteByName',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'routeName',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 145,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 145,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 145,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 145,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 145,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 147,
                  'char' => 14,
                ),
                4 => 
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
                          'value' => 'route',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 147,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 147,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 147,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 147,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 147,
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
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'Cannot obtain a route using the name \'',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 149,
                                  'char' => 60,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'routeName',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 149,
                                  'char' => 72,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 149,
                                'char' => 72,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '\'',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 150,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 150,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 150,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 150,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 151,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 156,
                  'char' => 15,
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
                      'variable' => 'uri',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'phalcon_replace_paths',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'route',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 157,
                                'char' => 23,
                              ),
                              'name' => 'getPattern',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 157,
                              'char' => 36,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 157,
                            'char' => 36,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'mcall',
                              'variable' => 
                              array (
                                'type' => 'variable',
                                'value' => 'route',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 158,
                                'char' => 23,
                              ),
                              'name' => 'getReversedPaths',
                              'call-type' => 1,
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 158,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 158,
                            'char' => 42,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'uri',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 160,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 160,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 160,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 160,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 161,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 163,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'local',
                'file' => '/app/phalcon/Url.zep',
                'line' => 163,
                'char' => 18,
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
                      'variable' => 'strUri',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'string',
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'uri',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 164,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 164,
                        'char' => 38,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 164,
                      'char' => 38,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 166,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'and',
                      'left' => 
                      array (
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'substr',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'baseUri',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 166,
                                  'char' => 30,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 166,
                                'char' => 30,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '-1',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 166,
                                  'char' => 34,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 166,
                                'char' => 34,
                              ),
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 37,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => '/',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 42,
                        ),
                        'right' => 
                        array (
                          'type' => 'greater',
                          'left' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'strlen',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'strUri',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 166,
                                  'char' => 57,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 166,
                                'char' => 57,
                              ),
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 59,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '2',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 166,
                        'char' => 64,
                      ),
                      'right' => 
                      array (
                        'type' => 'equals',
                        'left' => 
                        array (
                          'type' => 'array-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'strUri',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 72,
                          ),
                          'right' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 166,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 77,
                        ),
                        'right' => 
                        array (
                          'type' => 'char',
                          'value' => '/',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 83,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 166,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 166,
                      'char' => 83,
                    ),
                    'right' => 
                    array (
                      'type' => 'not-equals',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'strUri',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 91,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '1',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 166,
                          'char' => 93,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 166,
                        'char' => 96,
                      ),
                      'right' => 
                      array (
                        'type' => 'char',
                        'value' => '/',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 166,
                        'char' => 101,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 166,
                      'char' => 101,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 166,
                    'char' => 101,
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
                          'variable' => 'uri',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'baseUri',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 167,
                              'char' => 35,
                            ),
                            'right' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'substr',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'strUri',
                                    'file' => '/app/phalcon/Url.zep',
                                    'line' => 167,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 167,
                                  'char' => 50,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '1',
                                    'file' => '/app/phalcon/Url.zep',
                                    'line' => 167,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 167,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 167,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 167,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 167,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 168,
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
                        'type' => 'and',
                        'left' => 
                        array (
                          'type' => 'and',
                          'left' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'baseUri',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 29,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '/',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 34,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 169,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'strlen',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'strUri',
                                    'file' => '/app/phalcon/Url.zep',
                                    'line' => 169,
                                    'char' => 49,
                                  ),
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 169,
                                  'char' => 49,
                                ),
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 52,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '1',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 57,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 169,
                            'char' => 57,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 169,
                          'char' => 57,
                        ),
                        'right' => 
                        array (
                          'type' => 'equals',
                          'left' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'strUri',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 65,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 169,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 169,
                            'char' => 70,
                          ),
                          'right' => 
                          array (
                            'type' => 'char',
                            'value' => '/',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 169,
                            'char' => 75,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 169,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 169,
                        'char' => 75,
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
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'variable',
                                'value' => 'baseUri',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 170,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 170,
                              'char' => 38,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 171,
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
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'baseUri',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 172,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'strUri',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 172,
                                  'char' => 47,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 172,
                                'char' => 47,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 172,
                              'char' => 47,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 173,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 174,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 175,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 177,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'args',
                'file' => '/app/phalcon/Url.zep',
                'line' => 177,
                'char' => 17,
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
                      'variable' => 'queryString',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'http_build_query',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'args',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 178,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 178,
                            'char' => 52,
                          ),
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 178,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 178,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 180,
                  'char' => 14,
                ),
                1 => 
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
                          'value' => 'queryString',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 180,
                          'char' => 36,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 180,
                        'char' => 36,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'string',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 180,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 180,
                      'char' => 46,
                    ),
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'strlen',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'queryString',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 180,
                            'char' => 66,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 180,
                          'char' => 66,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 180,
                      'char' => 68,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 180,
                    'char' => 68,
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
                          'type' => 'fcall',
                          'name' => 'strpos',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 181,
                                'char' => 30,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 181,
                              'char' => 30,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '?',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 181,
                                'char' => 33,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 181,
                              'char' => 33,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 181,
                          'char' => 37,
                        ),
                        'right' => 
                        array (
                          'type' => 'bool',
                          'value' => 'false',
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 181,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 181,
                        'char' => 45,
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
                              'operator' => 'concat-assign',
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '&',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 182,
                                  'char' => 33,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'queryString',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 182,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 182,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 182,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 183,
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
                              'operator' => 'concat-assign',
                              'variable' => 'uri',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '?',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 184,
                                  'char' => 33,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'queryString',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 184,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 184,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 184,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 185,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 186,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 187,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 189,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'uri',
                'file' => '/app/phalcon/Url.zep',
                'line' => 189,
                'char' => 19,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 190,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a URL
     *
     *```php
     * // Generate a URL appending the URI to the base URI
     * echo $url->get("products/edit/1");
     *
     * // Generate a URL for a predefined route
     * echo $url->get(
     *     [
     *         "for"   => "blog-post",
     *         "title" => "some-cool-stuff",
     *         "year"  => "2015",
     *     ]
     * );
     *
     * // Generate a URL with GET arguments (/show/products?id=1&name=Carrots)
     * echo $url->get(
     *     "show/products",
     *     [
     *         "id"   => 1,
     *         "name" => "Carrots",
     *     ]
     * );
     *
     * // Generate an absolute URL by setting the third parameter as false.
     * echo $url->get(
     *     "https://phalconphp.com/",
     *     null,
     *     false
     * );
     *```
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 95,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 95,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 94,
          'last-line' => 194,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBasePath',
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
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 197,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'basePath',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 197,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 197,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 198,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the base path
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 196,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 196,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 195,
          'last-line' => 202,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getBaseUri',
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
                  'variable' => 'baseUri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 205,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'phpSelf',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 205,
                  'char' => 29,
                ),
                2 => 
                array (
                  'variable' => 'uri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 205,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 207,
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
                  'variable' => 'baseUri',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 207,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'baseUri',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 207,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 207,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 207,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 209,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'baseUri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 209,
                  'char' => 22,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 209,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 209,
                'char' => 29,
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
                      'value' => 'phpSelf',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 210,
                      'char' => 49,
                    ),
                    'right' => 
                    array (
                      'type' => 'array-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => '_SERVER',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 210,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'PHP_SELF',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 210,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 210,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 210,
                    'char' => 49,
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
                          'variable' => 'uri',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'phalcon_get_uri',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'phpSelf',
                                  'file' => '/app/phalcon/Url.zep',
                                  'line' => 211,
                                  'char' => 50,
                                ),
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 211,
                                'char' => 50,
                              ),
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 211,
                            'char' => 51,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 211,
                          'char' => 51,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 212,
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
                          'variable' => 'uri',
                          'expr' => 
                          array (
                            'type' => 'null',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 213,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 213,
                          'char' => 31,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 214,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 216,
                  'char' => 14,
                ),
                1 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 216,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 216,
                    'char' => 21,
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
                          'variable' => 'baseUri',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '/',
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 217,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 217,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 218,
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
                          'variable' => 'baseUri',
                          'expr' => 
                          array (
                            'type' => 'concat',
                            'left' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'string',
                                'value' => '/',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 219,
                                'char' => 33,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'uri',
                                'file' => '/app/phalcon/Url.zep',
                                'line' => 219,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 219,
                              'char' => 39,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => '/',
                              'file' => '/app/phalcon/Url.zep',
                              'line' => 219,
                              'char' => 41,
                            ),
                            'file' => '/app/phalcon/Url.zep',
                            'line' => 219,
                            'char' => 41,
                          ),
                          'file' => '/app/phalcon/Url.zep',
                          'line' => 219,
                          'char' => 41,
                        ),
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 220,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 222,
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
                      'property' => 'baseUri',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'baseUri',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 222,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 222,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 223,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 225,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'baseUri',
                'file' => '/app/phalcon/Url.zep',
                'line' => 225,
                'char' => 23,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 226,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the prefix for all the generated urls. By default /
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 204,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 204,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 203,
          'last-line' => 230,
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
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 233,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 233,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 233,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 234,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the DependencyInjector container
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
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 232,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Url.zep',
                'line' => 232,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 232,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 231,
          'last-line' => 250,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStatic',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'uri',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 251,
                'char' => 45,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 251,
              'char' => 45,
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
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 253,
                  'char' => 21,
                ),
                'name' => 'get',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'uri',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 254,
                      'char' => 16,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 254,
                    'char' => 16,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 255,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 255,
                    'char' => 17,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 256,
                      'char' => 17,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 256,
                    'char' => 17,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 257,
                        'char' => 18,
                      ),
                      'name' => 'getStaticBaseUri',
                      'call-type' => 1,
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 258,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 258,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 258,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 259,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a URL for a static resource
     *
     *```php
     * // Generate a URL for a static resource
     * echo $url->getStatic("img/logo.png");
     *
     * // Generate a URL for a static predefined route
     * echo $url->getStatic(
     *     [
     *         "for" => "logo-cdn",
     *     ]
     * );
     *```
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 252,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 252,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 251,
          'last-line' => 263,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getStaticBaseUri',
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
                  'variable' => 'staticBaseUri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 266,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 268,
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
                  'variable' => 'staticBaseUri',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 268,
                      'char' => 34,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'staticBaseUri',
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 268,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 268,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 268,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 270,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-identical',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'staticBaseUri',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 270,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 270,
                  'char' => 35,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 270,
                'char' => 35,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'staticBaseUri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 271,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 272,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 274,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 274,
                  'char' => 21,
                ),
                'name' => 'getBaseUri',
                'call-type' => 1,
                'file' => '/app/phalcon/Url.zep',
                'line' => 274,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 275,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the prefix for all the generated static urls. By default /
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 265,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 265,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 264,
          'last-line' => 283,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBasePath',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'basePath',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 284,
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
                  'property' => 'basePath',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'basePath',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 286,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 286,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 288,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Url.zep',
                'line' => 288,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 289,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a base path for all the generated paths
     *
     *```php
     * $url->setBasePath("/var/www/htdocs/");
     *```
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 285,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Url.zep',
                'line' => 285,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 285,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 284,
          'last-line' => 299,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setBaseUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'baseUri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 300,
              'char' => 47,
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
                  'property' => 'baseUri',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'baseUri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 302,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 302,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 304,
              'char' => 10,
            ),
            1 => 
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
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 304,
                    'char' => 17,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'staticBaseUri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 304,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 304,
                  'char' => 34,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 304,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 304,
                'char' => 41,
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
                      'property' => 'staticBaseUri',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'baseUri',
                        'file' => '/app/phalcon/Url.zep',
                        'line' => 305,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Url.zep',
                      'line' => 305,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 306,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 308,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Url.zep',
                'line' => 308,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 309,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a prefix for all the URIs to be generated
     *
     *```php
     * $url->setBaseUri("/invo/");
     *
     * $url->setBaseUri("/invo/index.php/");
     *```
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 301,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Url.zep',
                'line' => 301,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 301,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 300,
          'last-line' => 313,
          'char' => 19,
        ),
        8 => 
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 314,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 314,
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
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 316,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 316,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 317,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the DependencyInjector container
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Url.zep',
            'line' => 315,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 314,
          'last-line' => 325,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setStaticBaseUri',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'staticBaseUri',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 326,
              'char' => 59,
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
                  'property' => 'staticBaseUri',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'staticBaseUri',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 328,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 328,
                  'char' => 48,
                ),
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 330,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Url.zep',
                'line' => 330,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 331,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a prefix for all static URLs generated
     *
     *```php
     * $url->setStaticBaseUri("/invo/");
     *```
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
                  'value' => 'UrlInterface',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 327,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Url.zep',
                'line' => 327,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 327,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 326,
          'last-line' => 335,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'path',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'path',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Url.zep',
                'line' => 336,
                'char' => 44,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Url.zep',
              'line' => 336,
              'char' => 44,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 338,
                    'char' => 21,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'basePath',
                    'file' => '/app/phalcon/Url.zep',
                    'line' => 338,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 338,
                  'char' => 31,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'path',
                  'file' => '/app/phalcon/Url.zep',
                  'line' => 338,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Url.zep',
                'line' => 338,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Url.zep',
              'line' => 339,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a local path
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
                'file' => '/app/phalcon/Url.zep',
                'line' => 337,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Url.zep',
            'line' => 337,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Url.zep',
          'line' => 336,
          'last-line' => 340,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Url.zep',
      'line' => 37,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Url.zep',
    'line' => 37,
    'char' => 5,
  ),
);