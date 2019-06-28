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
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 13,
        'char' => 12,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'name' => 'Phalcon\\Mvc\\Controller\\BindModelInterface',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 14,
        'char' => 46,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Binder\\BindableInterface',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 15,
        'char' => 47,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'name' => 'Phalcon\\Cache\\Adapter\\AdapterInterface',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 16,
        'char' => 43,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'name' => 'ReflectionFunction',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 17,
        'char' => 23,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
        'name' => 'ReflectionMethod',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
        'line' => 18,
        'char' => 21,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
    'line' => 24,
    'char' => 2,
  ),
  8 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\Binding
 *
 * This is an class for binding models into params for handler
 *',
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
    'line' => 25,
    'char' => 5,
  ),
  9 => 
  array (
    'type' => 'class',
    'name' => 'Binder',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'BinderInterface',
        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
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
          'name' => 'boundModels',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 32,
            'char' => 32,
          ),
          'docblock' => '**
     * Array for storing active bound models
     *
     * @var array
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 32,
              'char' => 38,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 36,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'cache',
          'docblock' => '**
     * Cache object used for caching parameters for model binding
     *',
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 41,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'internalCache',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 42,
            'char' => 33,
          ),
          'docblock' => '**
     * Internal cache for caching parameters for model binding during request
     *',
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 46,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'originalValues',
          'default' => 
          array (
            'type' => 'empty-array',
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 47,
            'char' => 35,
          ),
          'docblock' => '**
     * Array for original values
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 47,
              'char' => 41,
            ),
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 51,
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
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 52,
                'char' => 56,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 52,
                'char' => 64,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 52,
              'char' => 64,
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
                  'property' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 54,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 54,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 55,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Mvc\\Model\\Binder constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 53,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 52,
          'last-line' => 59,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'bindToHandler',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'object',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 60,
              'char' => 49,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 60,
              'char' => 63,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'cacheKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 60,
              'char' => 80,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'methodName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 60,
                'char' => 107,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 60,
              'char' => 107,
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
                  'variable' => 'paramKey',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 62,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 62,
                  'char' => 32,
                ),
                2 => 
                array (
                  'variable' => 'boundModel',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 62,
                  'char' => 44,
                ),
                3 => 
                array (
                  'variable' => 'paramsCache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 62,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'paramValue',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 62,
                  'char' => 69,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 64,
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
                  'property' => 'originalValues',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 64,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 64,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 66,
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
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'and',
                    'left' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'list',
                        'left' => 
                        array (
                          'type' => 'instanceof',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'handler',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 66,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'Closure',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 66,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 66,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 66,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 66,
                      'char' => 53,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'methodName',
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 66,
                        'char' => 68,
                      ),
                      'right' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 66,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 66,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 66,
                    'char' => 74,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 66,
                  'char' => 76,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 66,
                'char' => 76,
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
                          'value' => 'You must specify methodName for handler or pass Closure as handler',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 69,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 69,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 69,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 70,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 72,
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
                  'property' => 'boundModels',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 72,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 72,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 73,
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
                  'variable' => 'paramsCache',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 73,
                      'char' => 32,
                    ),
                    'name' => 'getParamsFromCache',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 73,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 73,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 73,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 73,
                  'char' => 61,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 75,
              'char' => 10,
            ),
            5 => 
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
                    'value' => 'paramsCache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 75,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 75,
                  'char' => 32,
                ),
                'right' => 
                array (
                  'type' => 'string',
                  'value' => 'array',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 75,
                  'char' => 40,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 75,
                'char' => 40,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'for',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramsCache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 76,
                    'char' => 52,
                  ),
                  'key' => 'paramKey',
                  'value' => 'className',
                  'reverse' => 0,
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
                          'variable' => 'paramValue',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'params',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 77,
                              'char' => 40,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 77,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 77,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 77,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 78,
                      'char' => 19,
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
                          'variable' => 'boundModel',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 78,
                              'char' => 39,
                            ),
                            'name' => 'findBoundModel',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'paramValue',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 78,
                                  'char' => 65,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 78,
                                'char' => 65,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 78,
                                  'char' => 76,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 78,
                                'char' => 76,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 78,
                            'char' => 77,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 78,
                          'char' => 77,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 79,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'originalValues',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 79,
                              'char' => 50,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'paramValue',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 79,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 79,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 80,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 80,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'boundModel',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 80,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 80,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 81,
                      'char' => 19,
                    ),
                    4 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'boundModels',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 81,
                              'char' => 47,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'boundModel',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 81,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 81,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 82,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 84,
                  'char' => 18,
                ),
                1 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'params',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 84,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 85,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 87,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 87,
                  'char' => 21,
                ),
                'name' => 'getParamsFromReflection',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'handler',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 88,
                      'char' => 20,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 88,
                    'char' => 20,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'params',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 89,
                      'char' => 19,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 89,
                    'char' => 19,
                  ),
                  2 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cacheKey',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 90,
                      'char' => 21,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 90,
                    'char' => 21,
                  ),
                  3 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'methodName',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 92,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 92,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 92,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 93,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Bind models into params in proper handler
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 61,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 61,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 60,
          'last-line' => 97,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'findBoundModel',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'paramValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 98,
              'char' => 53,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'className',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 98,
              'char' => 71,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'scall',
                'dynamic-class' => 1,
                'class' => 'className',
                'dynamic' => 0,
                'name' => 'findFirst',
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'paramValue',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 100,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 100,
                    'char' => 49,
                  ),
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 100,
                'char' => 50,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 101,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Find the model by param value.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'object',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 98,
                'char' => 83,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'bool',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 99,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 99,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 98,
          'last-line' => 105,
          'char' => 22,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCache',
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
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 108,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'cache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 108,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 108,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 109,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets cache instance
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
                  'value' => 'AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 107,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 107,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 107,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 106,
          'last-line' => 113,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getParamsFromCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cacheKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 114,
              'char' => 58,
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
                  'variable' => 'cache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 116,
                  'char' => 18,
                ),
                1 => 
                array (
                  'variable' => 'internalParams',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 116,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 118,
              'char' => 10,
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
                  'value' => 'internalParams',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 118,
                  'char' => 64,
                ),
                'right' => 
                array (
                  'type' => 'array-access',
                  'left' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 118,
                      'char' => 39,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'internalCache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 118,
                      'char' => 53,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 118,
                    'char' => 53,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cacheKey',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 118,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 118,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 118,
                'char' => 64,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'internalParams',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 119,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 120,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 122,
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
                  'variable' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 122,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 122,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 122,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 122,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 124,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'identical',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 124,
                    'char' => 20,
                  ),
                  'right' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 124,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 124,
                  'char' => 28,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 124,
                      'char' => 37,
                    ),
                    'name' => 'exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 124,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 124,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 124,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 124,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 124,
                'char' => 55,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 125,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 126,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 128,
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
                  'variable' => 'internalParams',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 128,
                      'char' => 36,
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
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 128,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 128,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 128,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 128,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 129,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'internalCache',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'cacheKey',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 129,
                      'char' => 41,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'internalParams',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 129,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 129,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 131,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'internalParams',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 131,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 132,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get params classes from cache by key
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 114,
                'char' => 69,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 115,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 115,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 114,
          'last-line' => 136,
          'char' => 22,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getParamsFromReflection',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'handler',
              'const' => 0,
              'data-type' => 'object',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 137,
              'char' => 62,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'params',
              'const' => 0,
              'data-type' => 'array',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 137,
              'char' => 76,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'cacheKey',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 137,
              'char' => 93,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'methodName',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 137,
              'char' => 113,
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
                  'variable' => 'methodParams',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 139,
                  'char' => 25,
                ),
                1 => 
                array (
                  'variable' => 'reflection',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 139,
                  'char' => 37,
                ),
                2 => 
                array (
                  'variable' => 'paramKey',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 139,
                  'char' => 47,
                ),
                3 => 
                array (
                  'variable' => 'methodParam',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 139,
                  'char' => 60,
                ),
                4 => 
                array (
                  'variable' => 'className',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 139,
                  'char' => 71,
                ),
                5 => 
                array (
                  'variable' => 'realClasses',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 140,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 140,
                  'char' => 31,
                ),
                6 => 
                array (
                  'variable' => 'boundModel',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 140,
                  'char' => 43,
                ),
                7 => 
                array (
                  'variable' => 'cache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 140,
                  'char' => 50,
                ),
                8 => 
                array (
                  'variable' => 'handlerClass',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 140,
                  'char' => 64,
                ),
                9 => 
                array (
                  'variable' => 'reflectionClass',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 141,
                  'char' => 28,
                ),
                10 => 
                array (
                  'variable' => 'paramsKeys',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 141,
                  'char' => 40,
                ),
                11 => 
                array (
                  'variable' => 'paramValue',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 141,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 142,
              'char' => 13,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'array',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'paramsCache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 142,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 144,
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
                  'variable' => 'paramsCache',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 144,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 144,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 146,
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
                  'type' => 'variable',
                  'value' => 'methodName',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 146,
                  'char' => 24,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 146,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 146,
                'char' => 31,
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
                      'variable' => 'reflection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'ReflectionMethod',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handler',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 147,
                              'char' => 58,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 147,
                            'char' => 58,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'methodName',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 147,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 147,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 147,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 147,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 148,
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
                      'variable' => 'reflection',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'ReflectionFunction',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'handler',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 149,
                              'char' => 60,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 149,
                            'char' => 60,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 149,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 149,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 150,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 152,
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
                  'variable' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 152,
                      'char' => 26,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 152,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 152,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 152,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 154,
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
                  'variable' => 'methodParams',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'reflection',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 154,
                      'char' => 39,
                    ),
                    'name' => 'getParameters',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 154,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 154,
                  'char' => 55,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 155,
              'char' => 11,
            ),
            6 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'paramsKeys',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'array_keys',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 155,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 155,
                        'char' => 43,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 155,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 155,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 157,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'methodParams',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 157,
                'char' => 51,
              ),
              'key' => 'paramKey',
              'value' => 'methodParam',
              'reverse' => 0,
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
                      'variable' => 'reflectionClass',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'methodParam',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 158,
                          'char' => 47,
                        ),
                        'name' => 'getClass',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 158,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 158,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 160,
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
                      'value' => 'reflectionClass',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 160,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 160,
                    'char' => 33,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'continue',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 162,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 164,
                  'char' => 15,
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
                      'variable' => 'className',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'reflectionClass',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 164,
                          'char' => 45,
                        ),
                        'name' => 'getName',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 164,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 164,
                      'char' => 55,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 166,
                  'char' => 14,
                ),
                3 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not',
                    'left' => 
                    array (
                      'type' => 'isset',
                      'left' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 166,
                          'char' => 29,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paramKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 166,
                          'char' => 38,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 166,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 166,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 166,
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
                          'variable' => 'paramKey',
                          'expr' => 
                          array (
                            'type' => 'array-access',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramsKeys',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 167,
                              'char' => 42,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 167,
                              'char' => 51,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 167,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 167,
                          'char' => 52,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 168,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 170,
                  'char' => 15,
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
                      'variable' => 'boundModel',
                      'expr' => 
                      array (
                        'type' => 'null',
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 170,
                        'char' => 34,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 170,
                      'char' => 34,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 171,
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
                      'variable' => 'paramValue',
                      'expr' => 
                      array (
                        'type' => 'array-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'params',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 171,
                          'char' => 36,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paramKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 171,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 171,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 171,
                      'char' => 46,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 173,
                  'char' => 14,
                ),
                6 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'className',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 173,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'string',
                      'value' => 'Phalcon\\\\Mvc\\\\Model',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 173,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 173,
                    'char' => 49,
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
                          'type' => 'variable',
                          'value' => 'realClasses',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 174,
                          'char' => 33,
                        ),
                        'right' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 174,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 174,
                        'char' => 40,
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
                              'value' => 'handler',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 175,
                              'char' => 41,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'BindModelInterface',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 175,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 175,
                            'char' => 62,
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
                                  'variable' => 'handlerClass',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'get_class',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'handler',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 176,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 176,
                                        'char' => 61,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 176,
                                    'char' => 62,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 176,
                                  'char' => 62,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 177,
                              'char' => 27,
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
                                  'variable' => 'realClasses',
                                  'expr' => 
                                  array (
                                    'type' => 'scall',
                                    'dynamic-class' => 1,
                                    'class' => 'handlerClass',
                                    'dynamic' => 0,
                                    'name' => 'getModelName',
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 177,
                                    'char' => 73,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 177,
                                  'char' => 73,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 178,
                              'char' => 21,
                            ),
                          ),
                          'elseif_statements' => 
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
                                  'value' => 'handler',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 178,
                                  'char' => 47,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'BindableInterface',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 178,
                                  'char' => 67,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 178,
                                'char' => 67,
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
                                      'variable' => 'realClasses',
                                      'expr' => 
                                      array (
                                        'type' => 'mcall',
                                        'variable' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'handler',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 179,
                                          'char' => 51,
                                        ),
                                        'name' => 'getModelName',
                                        'call-type' => 1,
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 179,
                                        'char' => 66,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 179,
                                      'char' => 66,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 180,
                                  'char' => 21,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 180,
                              'char' => 26,
                            ),
                          ),
                          'else_statements' => 
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
                                      'value' => 'Handler must implement Phalcon\\\\Mvc\\\\Model\\\\Binder\\\\BindableInterface in order to use Phalcon\\\\Mvc\\\\Model as parameter',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 183,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 183,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 183,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 184,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 185,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 187,
                      'char' => 18,
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
                            'value' => 'realClasses',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 187,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 187,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'string',
                          'value' => 'array',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 187,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 187,
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
                              'type' => 'not',
                              'left' => 
                              array (
                                'type' => 'fetch',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'className',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 188,
                                  'char' => 73,
                                ),
                                'right' => 
                                array (
                                  'type' => 'array-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'realClasses',
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 188,
                                    'char' => 62,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'paramKey',
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 188,
                                    'char' => 71,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 188,
                                  'char' => 73,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 188,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 188,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 188,
                            'char' => 73,
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
                                          'value' => 'You should provide model class name for ',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 190,
                                          'char' => 70,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paramKey',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 190,
                                          'char' => 81,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 190,
                                        'char' => 81,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => ' parameter',
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 191,
                                        'char' => 25,
                                      ),
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 191,
                                      'char' => 25,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 191,
                                    'char' => 25,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 191,
                                'char' => 26,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 192,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 194,
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
                              'variable' => 'boundModel',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 194,
                                  'char' => 43,
                                ),
                                'name' => 'findBoundModel',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paramValue',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 194,
                                      'char' => 69,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 194,
                                    'char' => 69,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'className',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 194,
                                      'char' => 80,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 194,
                                    'char' => 80,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 194,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 194,
                              'char' => 81,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 195,
                          'char' => 17,
                        ),
                      ),
                      'elseif_statements' => 
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
                                'value' => 'realClasses',
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 195,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 195,
                              'char' => 46,
                            ),
                            'right' => 
                            array (
                              'type' => 'string',
                              'value' => 'string',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 195,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 195,
                            'char' => 55,
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
                                  'variable' => 'className',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'realClasses',
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 196,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 196,
                                  'char' => 48,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 197,
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
                                  'variable' => 'boundModel',
                                  'expr' => 
                                  array (
                                    'type' => 'mcall',
                                    'variable' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'this',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 197,
                                      'char' => 43,
                                    ),
                                    'name' => 'findBoundModel',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paramValue',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 197,
                                          'char' => 69,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 197,
                                        'char' => 69,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'className',
                                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                          'line' => 197,
                                          'char' => 80,
                                        ),
                                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                        'line' => 197,
                                        'char' => 80,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 197,
                                    'char' => 81,
                                  ),
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 197,
                                  'char' => 81,
                                ),
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 198,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 198,
                          'char' => 22,
                        ),
                      ),
                      'else_statements' => 
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
                                  'value' => 'getModelName should return array or string',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 201,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 201,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 201,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 202,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 203,
                      'char' => 13,
                    ),
                  ),
                  'elseif_statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'is_subclass_of',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'className',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 203,
                              'char' => 46,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 203,
                            'char' => 46,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'Phalcon\\\\Mvc\\\\Model',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 203,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 203,
                            'char' => 67,
                          ),
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 203,
                        'char' => 69,
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
                              'variable' => 'boundModel',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                  'line' => 204,
                                  'char' => 39,
                                ),
                                'name' => 'findBoundModel',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paramValue',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 204,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 204,
                                    'char' => 65,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'className',
                                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                      'line' => 204,
                                      'char' => 76,
                                    ),
                                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                    'line' => 204,
                                    'char' => 76,
                                  ),
                                ),
                                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                                'line' => 204,
                                'char' => 77,
                              ),
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 204,
                              'char' => 77,
                            ),
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 205,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 207,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 207,
                  'char' => 14,
                ),
                7 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'not-equals',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'boundModel',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 207,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'null',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 207,
                      'char' => 35,
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 207,
                    'char' => 35,
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
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'originalValues',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 208,
                              'char' => 50,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'paramValue',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 208,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 208,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 209,
                      'char' => 19,
                    ),
                    1 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'params',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 209,
                              'char' => 36,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'boundModel',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 209,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 209,
                          'char' => 50,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 210,
                      'char' => 19,
                    ),
                    2 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'object-property-array-index',
                          'operator' => 'assign',
                          'variable' => 'this',
                          'property' => 'boundModels',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 210,
                              'char' => 47,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'boundModel',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 210,
                            'char' => 61,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 210,
                          'char' => 61,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 211,
                      'char' => 19,
                    ),
                    3 => 
                    array (
                      'type' => 'let',
                      'assignments' => 
                      array (
                        0 => 
                        array (
                          'assign-type' => 'array-index',
                          'operator' => 'assign',
                          'variable' => 'paramsCache',
                          'index-expr' => 
                          array (
                            0 => 
                            array (
                              'type' => 'variable',
                              'value' => 'paramKey',
                              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                              'line' => 211,
                              'char' => 41,
                            ),
                          ),
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'className',
                            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                            'line' => 211,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 211,
                          'char' => 54,
                        ),
                      ),
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 212,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 213,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 215,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not-equals',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'cache',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 215,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'null',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 215,
                  'char' => 26,
                ),
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 215,
                'char' => 26,
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
                      'value' => 'cache',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 216,
                      'char' => 19,
                    ),
                    'name' => 'save',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cacheKey',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 216,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 216,
                        'char' => 33,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paramsCache',
                          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                          'line' => 216,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                        'line' => 216,
                        'char' => 46,
                      ),
                    ),
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 216,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 217,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 219,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property-array-index',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'internalCache',
                  'index-expr' => 
                  array (
                    0 => 
                    array (
                      'type' => 'variable',
                      'value' => 'cacheKey',
                      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                      'line' => 219,
                      'char' => 41,
                    ),
                  ),
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paramsCache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 219,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 219,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 221,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'params',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 221,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 222,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get modified params for handler using reflection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'list' => 
            array (
              0 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'array',
                'mandatory' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 138,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 138,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 137,
          'last-line' => 226,
          'char' => 22,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCache',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cache',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'AdapterInterface',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 227,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 227,
              'char' => 54,
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
                  'property' => 'cache',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cache',
                    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                    'line' => 229,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 229,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 231,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 231,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Mvc/Model/Binder.zep',
              'line' => 232,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Gets cache instance
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
                  'value' => 'BinderInterface',
                  'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                  'line' => 228,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/Binder.zep',
                'line' => 228,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/Binder.zep',
            'line' => 228,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Mvc/Model/Binder.zep',
          'line' => 227,
          'last-line' => 233,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/Binder.zep',
      'line' => 25,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Mvc/Model/Binder.zep',
    'line' => 25,
    'char' => 5,
  ),
);