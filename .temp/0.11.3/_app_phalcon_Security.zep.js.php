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
    'file' => '/app/phalcon/Security.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Security.zep',
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
        'file' => '/app/phalcon/Security.zep',
        'line' => 13,
        'char' => 24,
      ),
    ),
    'file' => '/app/phalcon/Security.zep',
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
        'name' => 'Phalcon\\Security\\Random',
        'file' => '/app/phalcon/Security.zep',
        'line' => 14,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Security.zep',
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
        'name' => 'Phalcon\\Security\\Exception',
        'file' => '/app/phalcon/Security.zep',
        'line' => 15,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Security.zep',
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
        'name' => 'Phalcon\\Di\\InjectionAwareInterface',
        'file' => '/app/phalcon/Security.zep',
        'line' => 16,
        'char' => 39,
      ),
    ),
    'file' => '/app/phalcon/Security.zep',
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
        'name' => 'Phalcon\\Session\\ManagerInterface',
        'alias' => 'SessionInterface',
        'file' => '/app/phalcon/Security.zep',
        'line' => 17,
        'char' => 57,
      ),
    ),
    'file' => '/app/phalcon/Security.zep',
    'line' => 35,
    'char' => 2,
  ),
  7 => 
  array (
    'type' => 'comment',
    'value' => '**
 * This component provides a set of functions to improve the security in Phalcon
 * applications
 *
 *```php
 * $login    = $this->request->getPost("login");
 * $password = $this->request->getPost("password");
 *
 * $user = Users::findFirstByLogin($login);
 *
 * if ($user) {
 *     if ($this->security->checkHash($password, $user->password)) {
 *         // The password is valid
 *     }
 * }
 *```
 *',
    'file' => '/app/phalcon/Security.zep',
    'line' => 36,
    'char' => 5,
  ),
  8 => 
  array (
    'type' => 'class',
    'name' => 'Security',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'InjectionAwareInterface',
        'file' => '/app/phalcon/Security.zep',
        'line' => 37,
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
          'file' => '/app/phalcon/Security.zep',
          'line' => 50,
          'char' => 13,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'defaultHash',
          'file' => '/app/phalcon/Security.zep',
          'line' => 51,
          'char' => 13,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'numberBytes',
          'default' => 
          array (
            'type' => 'int',
            'value' => '16',
            'file' => '/app/phalcon/Security.zep',
            'line' => 51,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 52,
          'char' => 13,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'random',
          'file' => '/app/phalcon/Security.zep',
          'line' => 53,
          'char' => 13,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'requestToken',
          'file' => '/app/phalcon/Security.zep',
          'line' => 54,
          'char' => 13,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'token',
          'file' => '/app/phalcon/Security.zep',
          'line' => 55,
          'char' => 13,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'tokenKey',
          'file' => '/app/phalcon/Security.zep',
          'line' => 56,
          'char' => 13,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'tokenKeySessionId',
          'default' => 
          array (
            'type' => 'string',
            'value' => '$PHALCON/CSRF/KEY$',
            'file' => '/app/phalcon/Security.zep',
            'line' => 56,
            'char' => 53,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 57,
          'char' => 13,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'tokenValueSessionId',
          'default' => 
          array (
            'type' => 'string',
            'value' => '$PHALCON/CSRF$',
            'file' => '/app/phalcon/Security.zep',
            'line' => 57,
            'char' => 51,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 58,
          'char' => 13,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'workFactor',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Security.zep',
            'line' => 58,
            'char' => 30,
          ),
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'set',
              'file' => '/app/phalcon/Security.zep',
              'line' => 58,
              'char' => 35,
            ),
            1 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Security.zep',
              'line' => 58,
              'char' => 41,
            ),
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 62,
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
                  'property' => 'random',
                  'expr' => 
                  array (
                    'type' => 'new',
                    'class' => 'Random',
                    'dynamic' => 0,
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 65,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 65,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 66,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Security constructor
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Security.zep',
            'line' => 64,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 63,
          'last-line' => 71,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkHash',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'password',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 72,
              'char' => 46,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'passwordHash',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 72,
              'char' => 67,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'maxPassLength',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Security.zep',
                'line' => 72,
                'char' => 90,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 72,
              'char' => 90,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'char',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'ch',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 74,
                  'char' => 16,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 75,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'cryptedHash',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 75,
                  'char' => 27,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 76,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'i',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 76,
                  'char' => 14,
                ),
                1 => 
                array (
                  'variable' => 'sum',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 76,
                  'char' => 19,
                ),
                2 => 
                array (
                  'variable' => 'cryptedLength',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 76,
                  'char' => 34,
                ),
                3 => 
                array (
                  'variable' => 'passwordLength',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 76,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 78,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'maxPassLength',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 78,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 78,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 78,
                  'char' => 31,
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
                          'value' => 'password',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 78,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 78,
                        'char' => 48,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 78,
                    'char' => 50,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'maxPassLength',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 78,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 78,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 78,
                'char' => 66,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 79,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 80,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 82,
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
                  'variable' => 'cryptedHash',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'string',
                    'right' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'crypt',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'password',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 82,
                            'char' => 50,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 82,
                          'char' => 50,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'passwordHash',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 82,
                            'char' => 64,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 82,
                          'char' => 64,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 82,
                      'char' => 65,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 82,
                    'char' => 65,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 82,
                  'char' => 65,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 84,
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
                  'variable' => 'cryptedLength',
                  'expr' => 
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
                          'value' => 'cryptedHash',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 84,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 84,
                        'char' => 47,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 84,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 84,
                  'char' => 48,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'passwordLength',
                  'expr' => 
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
                          'value' => 'passwordHash',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 85,
                          'char' => 49,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 85,
                        'char' => 49,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 85,
                    'char' => 50,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 85,
                  'char' => 50,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 87,
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
                  'operator' => 'concat-assign',
                  'variable' => 'cryptedHash',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'passwordHash',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 87,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 87,
                  'char' => 39,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 89,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'sum',
                  'expr' => 
                  array (
                    'type' => 'sub',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cryptedLength',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 89,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'passwordLength',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 89,
                      'char' => 49,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 89,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 89,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 91,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'passwordHash',
                'file' => '/app/phalcon/Security.zep',
                'line' => 91,
                'char' => 35,
              ),
              'key' => 'i',
              'value' => 'ch',
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
                      'variable' => 'sum',
                      'expr' => 
                      array (
                        'type' => 'bitwise_or',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'sum',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 92,
                          'char' => 27,
                        ),
                        'right' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'bitwise_xor',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'cryptedHash',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 92,
                                'char' => 41,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'i',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 92,
                                'char' => 43,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 92,
                              'char' => 45,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ch',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 92,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 92,
                            'char' => 49,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 92,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 92,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 92,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 93,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 95,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'identical',
                'left' => 
                array (
                  'type' => 'int',
                  'value' => '0',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 95,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'sum',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 95,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 95,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 96,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks a plain text password and its hash version to check if the
     * password matches
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 73,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 73,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 72,
          'last-line' => 101,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'checkToken',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tokenKey',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security.zep',
                'line' => 102,
                'char' => 51,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 102,
              'char' => 51,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'tokenValue',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Security.zep',
                'line' => 102,
                'char' => 74,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 102,
              'char' => 74,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'destroyIfValid',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'true',
                'file' => '/app/phalcon/Security.zep',
                'line' => 102,
                'char' => 102,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 102,
              'char' => 102,
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'request',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 40,
                ),
                3 => 
                array (
                  'variable' => 'equals',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 48,
                ),
                4 => 
                array (
                  'variable' => 'userToken',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 59,
                ),
                5 => 
                array (
                  'variable' => 'knownToken',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 104,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 106,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 106,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 106,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 106,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 106,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 106,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 106,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 108,
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
                      'value' => 'container',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 108,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 108,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 108,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 108,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 108,
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
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 110,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 110,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 111,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 111,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 111,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 112,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 114,
              'char' => 11,
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
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'SessionInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 114,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 114,
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
                            'value' => 'session',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 114,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 114,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 114,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 114,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 114,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 116,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'tokenKey',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 116,
                  'char' => 22,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 116,
                'char' => 22,
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
                      'variable' => 'tokenKey',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'session',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 117,
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
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 118,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'tokenKeySessionId',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 119,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 119,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 119,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 119,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 119,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 120,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 125,
              'char' => 10,
            ),
            5 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'tokenKey',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 125,
                  'char' => 22,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 125,
                'char' => 22,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'bool',
                    'value' => 'false',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 126,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 129,
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
                  'type' => 'variable',
                  'value' => 'tokenValue',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 129,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 129,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'request',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'container',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 130,
                          'char' => 37,
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
                              'value' => 'request',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 130,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 130,
                            'char' => 55,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 130,
                        'char' => 56,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 130,
                      'char' => 56,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 135,
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
                      'variable' => 'userToken',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'request',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 135,
                          'char' => 37,
                        ),
                        'name' => 'getPost',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'tokenKey',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 135,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 135,
                            'char' => 54,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'string',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 135,
                              'char' => 62,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 135,
                            'char' => 62,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 135,
                        'char' => 63,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 135,
                      'char' => 63,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 136,
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
                      'variable' => 'userToken',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tokenValue',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 137,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 137,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 138,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 143,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'knownToken',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 143,
                      'char' => 31,
                    ),
                    'name' => 'getRequestToken',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 143,
                    'char' => 49,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 143,
                  'char' => 49,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 145,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'equals',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'hash_equals',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'knownToken',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 145,
                          'char' => 44,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 145,
                        'char' => 44,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'userToken',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 145,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 145,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 145,
                    'char' => 56,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 145,
                  'char' => 56,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 150,
              'char' => 10,
            ),
            9 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'equals',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 150,
                  'char' => 20,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'destroyIfValid',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 150,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 150,
                'char' => 37,
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
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 151,
                      'char' => 18,
                    ),
                    'name' => 'destroyToken',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 151,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 152,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 154,
              'char' => 14,
            ),
            10 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'equals',
                'file' => '/app/phalcon/Security.zep',
                'line' => 154,
                'char' => 22,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 155,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Check if the CSRF token sent in the request is the same that the current
     * in session
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 103,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 103,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 102,
          'last-line' => 159,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'computeHmac',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 160,
              'char' => 44,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 160,
              'char' => 56,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'algo',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 160,
              'char' => 69,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'raw',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Security.zep',
                'line' => 160,
                'char' => 87,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 160,
              'char' => 87,
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
                  'variable' => 'hmac',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 162,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 164,
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
                  'variable' => 'hmac',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'hash_hmac',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'algo',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 164,
                          'char' => 34,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 164,
                        'char' => 34,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'data',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 164,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 164,
                        'char' => 40,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 164,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 164,
                        'char' => 45,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'raw',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 164,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 164,
                        'char' => 50,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 164,
                    'char' => 51,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 164,
                  'char' => 51,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 166,
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
                    'type' => 'variable',
                    'value' => 'hmac',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 166,
                    'char' => 27,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 166,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 166,
                'char' => 27,
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
                                'value' => 'Unknown hashing algorithm: %s',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 169,
                                'char' => 50,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 169,
                              'char' => 50,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'algo',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 171,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 171,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 172,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 172,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 172,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 173,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 175,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hmac',
                'file' => '/app/phalcon/Security.zep',
                'line' => 175,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 176,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Computes a HMAC
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 161,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 161,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 160,
          'last-line' => 180,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'destroyToken',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 183,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 183,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 185,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 185,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 185,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 185,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 185,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 185,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 185,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 187,
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
                      'value' => 'container',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 187,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 187,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 187,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 187,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 187,
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
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 189,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 189,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 190,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 190,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 190,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 191,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 193,
              'char' => 11,
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
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'SessionInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 193,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 193,
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
                            'value' => 'session',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 193,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 193,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 193,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 193,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 193,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 195,
              'char' => 15,
            ),
            4 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 195,
                  'char' => 17,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 195,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tokenKeySessionId',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 195,
                        'char' => 48,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 195,
                      'char' => 48,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 195,
                    'char' => 48,
                  ),
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 195,
                'char' => 49,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 196,
              'char' => 15,
            ),
            5 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 196,
                  'char' => 17,
                ),
                'name' => 'remove',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 196,
                        'char' => 30,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tokenValueSessionId',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 196,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 196,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 196,
                    'char' => 50,
                  ),
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 196,
                'char' => 51,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 198,
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
                  'property' => 'token',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 198,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 198,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 199,
              'char' => 11,
            ),
            7 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'tokenKey',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 199,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 199,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 200,
              'char' => 11,
            ),
            8 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'requestToken',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 200,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 200,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 202,
              'char' => 14,
            ),
            9 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Security.zep',
                'line' => 202,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 203,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes the value of the CSRF token and key from session
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
                  'value' => 'Security',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 182,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 182,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 182,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 181,
          'last-line' => 207,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getDefaultHash',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 210,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'defaultHash',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 210,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 210,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 211,
              'char' => 5,
            ),
          ),
          'docblock' => '**
      * Returns the default hash
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 208,
                'char' => 45,
              ),
              1 => 
              array (
                'type' => 'return-type-parameter',
                'data-type' => 'null',
                'mandatory' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 209,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 209,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 208,
          'last-line' => 215,
          'char' => 19,
        ),
        6 => 
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 218,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'container',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 218,
                  'char' => 31,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 218,
                'char' => 31,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 219,
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 217,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 217,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 217,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 216,
          'last-line' => 223,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRandom',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 226,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'random',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 226,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 226,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 227,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a secure random number generator instance
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
                  'value' => 'Random',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 225,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 225,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 225,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 224,
          'last-line' => 232,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRandomBytes',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 235,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'numberBytes',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 235,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 235,
                'char' => 33,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 236,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a number of bytes to be generated by the openssl pseudo random
     * generator
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 234,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 234,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 233,
          'last-line' => 240,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getRequestToken',
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'empty',
                'left' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 243,
                    'char' => 23,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'requestToken',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 243,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 243,
                  'char' => 37,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 243,
                'char' => 37,
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
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 244,
                      'char' => 25,
                    ),
                    'name' => 'getSessionToken',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 244,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 245,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 247,
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 247,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'requestToken',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 247,
                  'char' => 34,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 247,
                'char' => 34,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 248,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the value of the CSRF token for the current request.
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 242,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 242,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 241,
          'last-line' => 252,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSessionToken',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 255,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 255,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 257,
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
                  'variable' => 'container',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'DiInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 257,
                      'char' => 54,
                    ),
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 257,
                        'char' => 44,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 257,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 257,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 257,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 257,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 259,
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
                      'value' => 'container',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 259,
                      'char' => 39,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 259,
                    'char' => 39,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'object',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 259,
                    'char' => 48,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 259,
                  'char' => 48,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 259,
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
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 261,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 261,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 262,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 262,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 262,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 263,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 265,
              'char' => 11,
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
                  'variable' => 'session',
                  'expr' => 
                  array (
                    'type' => 'type-hint',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'SessionInterface',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 265,
                      'char' => 71,
                    ),
                    'right' => 
                    array (
                      'type' => 'mcall',
                      'variable' => 
                      array (
                        'type' => 'variable',
                        'value' => 'container',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 265,
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
                            'value' => 'session',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 265,
                            'char' => 70,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 265,
                          'char' => 70,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 265,
                      'char' => 71,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 265,
                    'char' => 71,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 265,
                  'char' => 71,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 267,
              'char' => 14,
            ),
            4 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 267,
                  'char' => 24,
                ),
                'name' => 'get',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 267,
                        'char' => 34,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'tokenValueSessionId',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 267,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 267,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 267,
                    'char' => 54,
                  ),
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 267,
                'char' => 55,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 268,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the value of the CSRF token in session
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 254,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 254,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 253,
          'last-line' => 273,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getSaltBytes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'numberBytes',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Security.zep',
                'line' => 274,
                'char' => 53,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 274,
              'char' => 53,
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
                  'variable' => 'safeBytes',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 276,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 278,
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
                  'type' => 'variable',
                  'value' => 'numberBytes',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 278,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 278,
                'char' => 25,
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
                      'variable' => 'numberBytes',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 279,
                            'char' => 42,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'numberBytes',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 279,
                            'char' => 54,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 279,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 279,
                        'char' => 54,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 279,
                      'char' => 54,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 280,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 282,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'loop',
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
                      'variable' => 'safeBytes',
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
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 283,
                            'char' => 34,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'random',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 283,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 283,
                          'char' => 42,
                        ),
                        'name' => 'base64Safe',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'numberBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 283,
                              'char' => 65,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 283,
                            'char' => 65,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 283,
                        'char' => 66,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 283,
                      'char' => 66,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 285,
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
                      'type' => 'variable',
                      'value' => 'safeBytes',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 285,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'greater-equal',
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
                              'value' => 'safeBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 285,
                              'char' => 45,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 285,
                            'char' => 45,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 285,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'numberBytes',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 285,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 285,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 285,
                    'char' => 61,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 287,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 288,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 290,
              'char' => 14,
            ),
            3 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'safeBytes',
                'file' => '/app/phalcon/Security.zep',
                'line' => 290,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 291,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generate a >22-length pseudo random string to be used as salt for
     * passwords
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 275,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 275,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 274,
          'last-line' => 296,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getToken',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 299,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 299,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 301,
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
                  'type' => 'null',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 301,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 301,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'token',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 301,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 301,
                  'char' => 33,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 301,
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
                      'assign-type' => 'object-property',
                      'operator' => 'assign',
                      'variable' => 'this',
                      'property' => 'requestToken',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 302,
                          'char' => 43,
                        ),
                        'name' => 'getSessionToken',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 302,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 302,
                      'char' => 61,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 303,
                  'char' => 15,
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
                      'property' => 'token',
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
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 303,
                            'char' => 36,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'random',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 303,
                            'char' => 44,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 303,
                          'char' => 44,
                        ),
                        'name' => 'base64Safe',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 303,
                                'char' => 61,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numberBytes',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 303,
                                'char' => 73,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 303,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 303,
                            'char' => 73,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 303,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 303,
                      'char' => 74,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 305,
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
                      'variable' => 'container',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'DiInterface',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 305,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 305,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 305,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 305,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 305,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 305,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 307,
                  'char' => 14,
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
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 307,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 307,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 307,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 307,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 307,
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
                                    'value' => 'the \'session\' service',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 309,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 309,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 310,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 310,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 310,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 311,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 313,
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
                      'variable' => 'session',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SessionInterface',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 313,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 313,
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
                                'value' => 'session',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 313,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 313,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 313,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 313,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 313,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 315,
                  'char' => 19,
                ),
                5 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 315,
                      'char' => 21,
                    ),
                    'name' => 'set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 316,
                            'char' => 22,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tokenValueSessionId',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 316,
                            'char' => 42,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 316,
                          'char' => 42,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 316,
                        'char' => 42,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 317,
                            'char' => 22,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'token',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 318,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 318,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 318,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 318,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 319,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 321,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 321,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'token',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 321,
                  'char' => 27,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 321,
                'char' => 27,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 322,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a pseudo random token value to be used as input\'s value in a
     * CSRF check
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 298,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 298,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 297,
          'last-line' => 327,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getTokenKey',
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
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 330,
                  'char' => 22,
                ),
                1 => 
                array (
                  'variable' => 'session',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 330,
                  'char' => 31,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 332,
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
                  'type' => 'null',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 332,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'property-access',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'this',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 332,
                    'char' => 26,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tokenKey',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 332,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 332,
                  'char' => 36,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 332,
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
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 333,
                          'char' => 58,
                        ),
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 333,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 333,
                            'char' => 58,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 333,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 333,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 333,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 335,
                  'char' => 14,
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
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 335,
                          'char' => 43,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 335,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'object',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 335,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 335,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 335,
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
                                    'value' => 'the \'session\' service',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 337,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 337,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 338,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 338,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 338,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 339,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 341,
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
                      'property' => 'tokenKey',
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
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 341,
                            'char' => 39,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'random',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 341,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 341,
                          'char' => 47,
                        ),
                        'name' => 'base64Safe',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 341,
                                'char' => 64,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'numberBytes',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 341,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 341,
                              'char' => 76,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 341,
                            'char' => 76,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 341,
                        'char' => 77,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 341,
                      'char' => 77,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 343,
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
                      'variable' => 'session',
                      'expr' => 
                      array (
                        'type' => 'type-hint',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'SessionInterface',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 343,
                          'char' => 75,
                        ),
                        'right' => 
                        array (
                          'type' => 'mcall',
                          'variable' => 
                          array (
                            'type' => 'variable',
                            'value' => 'container',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 343,
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
                                'value' => 'session',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 343,
                                'char' => 74,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 343,
                              'char' => 74,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 343,
                          'char' => 75,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 343,
                        'char' => 75,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 343,
                      'char' => 75,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 345,
                  'char' => 19,
                ),
                4 => 
                array (
                  'type' => 'mcall',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'session',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 345,
                      'char' => 21,
                    ),
                    'name' => 'set',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 346,
                            'char' => 22,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tokenKeySessionId',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 346,
                            'char' => 40,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 346,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 346,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 347,
                            'char' => 22,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'tokenKey',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 348,
                            'char' => 13,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 348,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 348,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 348,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 349,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 351,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 351,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'tokenKey',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 351,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 351,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 352,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Generates a pseudo random token key to be used as input\'s name in a CSRF
     * check
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 329,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 329,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 328,
          'last-line' => 356,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'hash',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'password',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 357,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'workFactor',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'int',
                'value' => '0',
                'file' => '/app/phalcon/Security.zep',
                'line' => 357,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 357,
              'char' => 61,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'declare',
              'data-type' => 'int',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'hash',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 359,
                  'char' => 17,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 360,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'string',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'variant',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 360,
                  'char' => 23,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 361,
              'char' => 11,
            ),
            2 => 
            array (
              'type' => 'declare',
              'data-type' => 'variable',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'saltBytes',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 361,
                  'char' => 22,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 363,
              'char' => 10,
            ),
            3 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'not',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'workFactor',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 363,
                  'char' => 24,
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 363,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'workFactor',
                      'expr' => 
                      array (
                        'type' => 'cast',
                        'left' => 'int',
                        'right' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 364,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'workFactor',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 364,
                            'char' => 52,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 364,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 364,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 364,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 365,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 367,
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
                  'variable' => 'hash',
                  'expr' => 
                  array (
                    'type' => 'cast',
                    'left' => 'int',
                    'right' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 367,
                        'char' => 31,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'defaultHash',
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 367,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 367,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 367,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 367,
                  'char' => 43,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 369,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hash',
                'file' => '/app/phalcon/Security.zep',
                'line' => 369,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 371,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH_A',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 371,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 371,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'a',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 372,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 372,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 373,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 375,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 375,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 375,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH_X',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 375,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 375,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'x',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 376,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 376,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 377,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 379,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 379,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 379,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH_Y',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 379,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 379,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'y',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 380,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 380,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 381,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 383,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 383,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 383,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_MD5',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 383,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 383,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '1',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 384,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 384,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 385,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 387,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 387,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 387,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_SHA256',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 387,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 387,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '5',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 388,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 388,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 389,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 391,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 391,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 391,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_SHA512',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 391,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 391,
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => '6',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 392,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 392,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 393,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 395,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 395,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 395,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_DEFAULT',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 395,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 395,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 396,
                  'char' => 19,
                ),
                7 => 
                array (
                  'type' => 'default',
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
                          'variable' => 'variant',
                          'expr' => 
                          array (
                            'type' => 'string',
                            'value' => 'y',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 397,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 397,
                          'char' => 32,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 398,
                      'char' => 21,
                    ),
                    1 => 
                    array (
                      'type' => 'break',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 399,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 399,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 401,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'switch',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'hash',
                'file' => '/app/phalcon/Security.zep',
                'line' => 401,
                'char' => 21,
              ),
              'clauses' => 
              array (
                0 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 403,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_STD_DES',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 403,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 403,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 404,
                  'char' => 16,
                ),
                1 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 404,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_EXT_DES',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 404,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 404,
                    'char' => 37,
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
                          'value' => 'hash',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 411,
                          'char' => 26,
                        ),
                        'right' => 
                        array (
                          'type' => 'static-constant-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'self',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 411,
                            'char' => 48,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'CRYPT_EXT_DES',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 411,
                            'char' => 48,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 411,
                          'char' => 48,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 411,
                        'char' => 48,
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
                              'variable' => 'saltBytes',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'string',
                                  'value' => '_',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 412,
                                  'char' => 39,
                                ),
                                'right' => 
                                array (
                                  'type' => 'mcall',
                                  'variable' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 412,
                                    'char' => 46,
                                  ),
                                  'name' => 'getSaltBytes',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '8',
                                        'file' => '/app/phalcon/Security.zep',
                                        'line' => 412,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 412,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 412,
                                  'char' => 62,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 412,
                                'char' => 62,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 412,
                              'char' => 62,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 413,
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
                              'variable' => 'saltBytes',
                              'expr' => 
                              array (
                                'type' => 'mcall',
                                'variable' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'this',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 414,
                                  'char' => 42,
                                ),
                                'name' => 'getSaltBytes',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '2',
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 414,
                                      'char' => 57,
                                    ),
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 414,
                                    'char' => 57,
                                  ),
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 414,
                                'char' => 58,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 414,
                              'char' => 58,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 415,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 417,
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
                              'value' => 'saltBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 417,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 417,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 417,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 417,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 417,
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
                                  'value' => 'Unable to get random bytes for the salt',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 420,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 420,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 420,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 421,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 423,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'crypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'password',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 423,
                              'char' => 38,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 423,
                            'char' => 38,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'saltBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 423,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 423,
                            'char' => 49,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 423,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 425,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 425,
                  'char' => 16,
                ),
                2 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 425,
                      'char' => 33,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_MD5',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 425,
                      'char' => 33,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 425,
                    'char' => 33,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 426,
                  'char' => 16,
                ),
                3 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 426,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_SHA256',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 426,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 426,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 427,
                  'char' => 16,
                ),
                4 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 427,
                      'char' => 36,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_SHA512',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 427,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 427,
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
                          'variable' => 'saltBytes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 434,
                              'char' => 38,
                            ),
                            'name' => 'getSaltBytes',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'ternary',
                                  'left' => 
                                  array (
                                    'type' => 'equals',
                                    'left' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'hash',
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 434,
                                      'char' => 58,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'static-constant-access',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'self',
                                        'file' => '/app/phalcon/Security.zep',
                                        'line' => 434,
                                        'char' => 76,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'CRYPT_MD5',
                                        'file' => '/app/phalcon/Security.zep',
                                        'line' => 434,
                                        'char' => 76,
                                      ),
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 434,
                                      'char' => 76,
                                    ),
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 434,
                                    'char' => 76,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '12',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 434,
                                    'char' => 81,
                                  ),
                                  'extra' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '16',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 434,
                                    'char' => 85,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 434,
                                  'char' => 85,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 434,
                                'char' => 85,
                              ),
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 434,
                            'char' => 86,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 434,
                          'char' => 86,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 436,
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
                              'value' => 'saltBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 436,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 436,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 436,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 436,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 436,
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
                                  'value' => 'Unable to get random bytes for the salt',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 439,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 439,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 439,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 440,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 442,
                      'char' => 22,
                    ),
                    2 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'crypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'password',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 443,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 443,
                            'char' => 29,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'string',
                                      'value' => '$',
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 443,
                                      'char' => 33,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'variant',
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 443,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 443,
                                    'char' => 43,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '$',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 443,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 443,
                                  'char' => 48,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'saltBytes',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 443,
                                  'char' => 60,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 443,
                                'char' => 60,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '$',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 444,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 444,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 444,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 444,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 446,
                      'char' => 16,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 446,
                  'char' => 16,
                ),
                5 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 446,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_DEFAULT',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 446,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 446,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 447,
                  'char' => 16,
                ),
                6 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 447,
                      'char' => 38,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 447,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 447,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 448,
                  'char' => 16,
                ),
                7 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 448,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH_X',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 448,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 448,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 449,
                  'char' => 16,
                ),
                8 => 
                array (
                  'type' => 'case',
                  'expr' => 
                  array (
                    'type' => 'static-constant-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'self',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 449,
                      'char' => 40,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'CRYPT_BLOWFISH_Y',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 449,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 449,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 450,
                  'char' => 19,
                ),
                9 => 
                array (
                  'type' => 'default',
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
                          'variable' => 'saltBytes',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 463,
                              'char' => 38,
                            ),
                            'name' => 'getSaltBytes',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '22',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 463,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 463,
                                'char' => 54,
                              ),
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 463,
                            'char' => 55,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 463,
                          'char' => 55,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 465,
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
                              'value' => 'saltBytes',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 465,
                              'char' => 47,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 465,
                            'char' => 47,
                          ),
                          'right' => 
                          array (
                            'type' => 'string',
                            'value' => 'string',
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 465,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 465,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 465,
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
                                  'value' => 'Unable to get random bytes for the salt',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 468,
                                  'char' => 21,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 468,
                                'char' => 21,
                              ),
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 468,
                            'char' => 22,
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 469,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 471,
                      'char' => 18,
                    ),
                    2 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'less',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'workFactor',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 471,
                          'char' => 31,
                        ),
                        'right' => 
                        array (
                          'type' => 'int',
                          'value' => '4',
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 471,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 471,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'workFactor',
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '4',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 472,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 472,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 473,
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
                            'type' => 'greater',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'workFactor',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 473,
                              'char' => 37,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '31',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 473,
                              'char' => 42,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 473,
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
                                  'variable' => 'workFactor',
                                  'expr' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '31',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 474,
                                    'char' => 40,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 474,
                                  'char' => 40,
                                ),
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 475,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Security.zep',
                          'line' => 477,
                          'char' => 22,
                        ),
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 477,
                      'char' => 22,
                    ),
                    3 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'crypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'password',
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 478,
                              'char' => 29,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 478,
                            'char' => 29,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'concat',
                              'left' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'concat',
                                  'left' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'concat',
                                      'left' => 
                                      array (
                                        'type' => 'concat',
                                        'left' => 
                                        array (
                                          'type' => 'string',
                                          'value' => '$2',
                                          'file' => '/app/phalcon/Security.zep',
                                          'line' => 479,
                                          'char' => 24,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'variant',
                                          'file' => '/app/phalcon/Security.zep',
                                          'line' => 479,
                                          'char' => 34,
                                        ),
                                        'file' => '/app/phalcon/Security.zep',
                                        'line' => 479,
                                        'char' => 34,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '$',
                                        'file' => '/app/phalcon/Security.zep',
                                        'line' => 479,
                                        'char' => 38,
                                      ),
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 479,
                                      'char' => 38,
                                    ),
                                    'right' => 
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
                                            'value' => '%02s',
                                            'file' => '/app/phalcon/Security.zep',
                                            'line' => 479,
                                            'char' => 52,
                                          ),
                                          'file' => '/app/phalcon/Security.zep',
                                          'line' => 479,
                                          'char' => 52,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'workFactor',
                                            'file' => '/app/phalcon/Security.zep',
                                            'line' => 479,
                                            'char' => 64,
                                          ),
                                          'file' => '/app/phalcon/Security.zep',
                                          'line' => 479,
                                          'char' => 64,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Security.zep',
                                      'line' => 479,
                                      'char' => 66,
                                    ),
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 479,
                                    'char' => 66,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '$',
                                    'file' => '/app/phalcon/Security.zep',
                                    'line' => 479,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 479,
                                  'char' => 70,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'saltBytes',
                                  'file' => '/app/phalcon/Security.zep',
                                  'line' => 479,
                                  'char' => 82,
                                ),
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 479,
                                'char' => 82,
                              ),
                              'right' => 
                              array (
                                'type' => 'string',
                                'value' => '$',
                                'file' => '/app/phalcon/Security.zep',
                                'line' => 480,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Security.zep',
                              'line' => 480,
                              'char' => 17,
                            ),
                            'file' => '/app/phalcon/Security.zep',
                            'line' => 480,
                            'char' => 17,
                          ),
                        ),
                        'file' => '/app/phalcon/Security.zep',
                        'line' => 480,
                        'char' => 18,
                      ),
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 481,
                      'char' => 9,
                    ),
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 481,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 483,
              'char' => 14,
            ),
            7 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'string',
                'value' => '',
                'file' => '/app/phalcon/Security.zep',
                'line' => 483,
                'char' => 16,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 484,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Creates a password hash using bcrypt with a pseudo random salt
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 358,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 358,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 357,
          'last-line' => 488,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isLegacyHash',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'passwordHash',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 489,
              'char' => 53,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'starts_with',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'passwordHash',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 491,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 491,
                    'char' => 40,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'string',
                      'value' => '$2a$',
                      'file' => '/app/phalcon/Security.zep',
                      'line' => 491,
                      'char' => 46,
                    ),
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 491,
                    'char' => 46,
                  ),
                ),
                'file' => '/app/phalcon/Security.zep',
                'line' => 491,
                'char' => 47,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 492,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Checks if a password hash is a valid bcrypt\'s hash
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 490,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 490,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 489,
          'last-line' => 496,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setDefaultHash',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'defaultHash',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 497,
              'char' => 51,
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
                  'property' => 'defaultHash',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'defaultHash',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 499,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 499,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 501,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Security.zep',
                'line' => 501,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 502,
              'char' => 5,
            ),
          ),
          'docblock' => '**
      * Sets the default hash
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
                  'value' => 'Security',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 498,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 498,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 498,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 497,
          'last-line' => 506,
          'char' => 19,
        ),
        17 => 
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
                'file' => '/app/phalcon/Security.zep',
                'line' => 507,
                'char' => 49,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 507,
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
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 509,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 509,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 510,
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
            'file' => '/app/phalcon/Security.zep',
            'line' => 508,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 507,
          'last-line' => 515,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRandomBytes',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'randomBytes',
              'const' => 0,
              'data-type' => 'long',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Security.zep',
              'line' => 516,
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
                  'property' => 'numberBytes',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'randomBytes',
                    'file' => '/app/phalcon/Security.zep',
                    'line' => 518,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 518,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 520,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Security.zep',
                'line' => 520,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Security.zep',
              'line' => 521,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets a number of bytes to be generated by the openssl pseudo random
     * generator
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
                  'value' => 'Security',
                  'file' => '/app/phalcon/Security.zep',
                  'line' => 517,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Security.zep',
                'line' => 517,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Security.zep',
            'line' => 517,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 516,
          'last-line' => 522,
          'char' => 19,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_DEFAULT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Security.zep',
            'line' => 38,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 39,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_BLOWFISH',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Security.zep',
            'line' => 39,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 40,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_BLOWFISH_A',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Security.zep',
            'line' => 40,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 41,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_BLOWFISH_X',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Security.zep',
            'line' => 41,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 42,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_BLOWFISH_Y',
          'default' => 
          array (
            'type' => 'int',
            'value' => '7',
            'file' => '/app/phalcon/Security.zep',
            'line' => 42,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 43,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_EXT_DES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Security.zep',
            'line' => 43,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 44,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_MD5',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Security.zep',
            'line' => 44,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 45,
          'char' => 9,
        ),
        7 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_SHA256',
          'default' => 
          array (
            'type' => 'int',
            'value' => '8',
            'file' => '/app/phalcon/Security.zep',
            'line' => 45,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 46,
          'char' => 9,
        ),
        8 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_SHA512',
          'default' => 
          array (
            'type' => 'int',
            'value' => '9',
            'file' => '/app/phalcon/Security.zep',
            'line' => 46,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 47,
          'char' => 9,
        ),
        9 => 
        array (
          'type' => 'const',
          'name' => 'CRYPT_STD_DES',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Security.zep',
            'line' => 47,
            'char' => 31,
          ),
          'file' => '/app/phalcon/Security.zep',
          'line' => 49,
          'char' => 13,
        ),
      ),
      'file' => '/app/phalcon/Security.zep',
      'line' => 36,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Security.zep',
    'line' => 36,
    'char' => 5,
  ),
);