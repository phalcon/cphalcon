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
    'file' => '/app/phalcon/Crypt.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon',
    'file' => '/app/phalcon/Crypt.zep',
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
        'name' => 'Phalcon\\CryptInterface',
        'file' => '/app/phalcon/Crypt.zep',
        'line' => 13,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Crypt.zep',
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
        'name' => 'Phalcon\\Crypt\\Exception',
        'file' => '/app/phalcon/Crypt.zep',
        'line' => 14,
        'char' => 28,
      ),
    ),
    'file' => '/app/phalcon/Crypt.zep',
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
        'name' => 'Phalcon\\Crypt\\Mismatch',
        'file' => '/app/phalcon/Crypt.zep',
        'line' => 15,
        'char' => 27,
      ),
    ),
    'file' => '/app/phalcon/Crypt.zep',
    'line' => 34,
    'char' => 2,
  ),
  5 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Provides encryption capabilities to Phalcon applications.
 *
 * ```php
 * use Phalcon\\Crypt;
 *
 * $crypt = new Crypt();
 *
 * $crypt->setCipher(\'aes-256-ctr\');
 *
 * $key  = "T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3";
 * $text = "The message to be encrypted";
 *
 * $encrypted = $crypt->encrypt($text, $key);
 *
 * echo $crypt->decrypt($encrypted, $key);
 * ```
 *',
    'file' => '/app/phalcon/Crypt.zep',
    'line' => 35,
    'char' => 5,
  ),
  6 => 
  array (
    'type' => 'class',
    'name' => 'Crypt',
    'abstract' => 0,
    'final' => 0,
    'implements' => 
    array (
      0 => 
      array (
        'type' => 'variable',
        'value' => 'CryptInterface',
        'file' => '/app/phalcon/Crypt.zep',
        'line' => 36,
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
          'name' => 'authTag',
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 48,
              'char' => 29,
            ),
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 51,
          'char' => 6,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'authData',
          'default' => 
          array (
            'type' => 'string',
            'value' => '',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 52,
            'char' => 27,
          ),
          'docblock' => '**
     * @var string
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 52,
              'char' => 33,
            ),
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 55,
          'char' => 6,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'authTagLength',
          'default' => 
          array (
            'type' => 'int',
            'value' => '16',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 56,
            'char' => 34,
          ),
          'docblock' => '**
     * @var int
     *',
          'shortcuts' => 
          array (
            0 => 
            array (
              'type' => 'shortcut',
              'name' => 'get',
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 56,
              'char' => 40,
            ),
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 59,
          'char' => 6,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'key',
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 64,
          'char' => 6,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'padding',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 65,
            'char' => 26,
          ),
          'docblock' => '**
     * @var int
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 69,
          'char' => 6,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'cipher',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'aes-256-cfb',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 70,
            'char' => 35,
          ),
          'docblock' => '**
     * @var string
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 75,
          'char' => 6,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'availableCiphers',
          'docblock' => '**
     * Available cipher methods.
     * @var array
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 81,
          'char' => 6,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'ivLength',
          'default' => 
          array (
            'type' => 'int',
            'value' => '16',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 82,
            'char' => 28,
          ),
          'docblock' => '**
     * The cipher iv length.
     * @var int
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 87,
          'char' => 6,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'hashAlgo',
          'default' => 
          array (
            'type' => 'string',
            'value' => 'sha256',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 88,
            'char' => 32,
          ),
          'docblock' => '**
     * The name of hashing algorithm.
     * @var string
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 94,
          'char' => 6,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'property',
          'name' => 'useSigning',
          'default' => 
          array (
            'type' => 'bool',
            'value' => 'true',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 95,
            'char' => 32,
          ),
          'docblock' => '**
     * Whether calculating message digest enabled or not.
     *
     * @var bool
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 99,
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
              'name' => 'cipher',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'string',
                'value' => 'aes-256-cfb',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 100,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 100,
              'char' => 61,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'useSigning',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 100,
                'char' => 86,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 100,
              'char' => 86,
            ),
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 102,
                  'char' => 14,
                ),
                'name' => 'initializeAvailableCiphers',
                'call-type' => 1,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 102,
                'char' => 43,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 104,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 104,
                  'char' => 14,
                ),
                'name' => 'setCipher',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 104,
                      'char' => 31,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 104,
                    'char' => 31,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 104,
                'char' => 32,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 105,
              'char' => 12,
            ),
            2 => 
            array (
              'type' => 'mcall',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 105,
                  'char' => 14,
                ),
                'name' => 'useSigning',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'useSigning',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 105,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 105,
                    'char' => 36,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 105,
                'char' => 37,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 106,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Phalcon\\Crypt constructor.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 101,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 100,
          'last-line' => 117,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'decrypt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 118,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 118,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 118,
              'char' => 61,
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
                  'variable' => 'authData',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'authTag',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'decryptKey',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 42,
                ),
                3 => 
                array (
                  'variable' => 'ivLength',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 52,
                ),
                4 => 
                array (
                  'variable' => 'cipher',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 60,
                ),
                5 => 
                array (
                  'variable' => 'mode',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 66,
                ),
                6 => 
                array (
                  'variable' => 'blockSize',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 120,
                  'char' => 77,
                ),
                7 => 
                array (
                  'variable' => 'decrypted',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 22,
                ),
                8 => 
                array (
                  'variable' => 'ciphertext',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 34,
                ),
                9 => 
                array (
                  'variable' => 'hashAlgo',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 44,
                ),
                10 => 
                array (
                  'variable' => 'hashLength',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 56,
                ),
                11 => 
                array (
                  'variable' => 'iv',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 60,
                ),
                12 => 
                array (
                  'variable' => 'hash',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 121,
                  'char' => 66,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 123,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 123,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 123,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 123,
                'char' => 29,
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
                      'variable' => 'decryptKey',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 124,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 124,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 124,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 124,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 125,
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
                      'variable' => 'decryptKey',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 126,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 126,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 127,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 129,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'decryptKey',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 129,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 129,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 129,
                'char' => 38,
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
                          'value' => 'Decryption key cannot be empty',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 130,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 130,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 130,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 131,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 133,
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
                  'variable' => 'cipher',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 133,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 133,
                      'char' => 36,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 133,
                    'char' => 36,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 133,
                  'char' => 36,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'mode',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
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
                                'value' => 'cipher',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 134,
                                'char' => 48,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 134,
                              'char' => 48,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'strrpos',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'cipher',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 134,
                                        'char' => 64,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 134,
                                      'char' => 64,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '-',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 134,
                                        'char' => 67,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 134,
                                      'char' => 67,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 134,
                                  'char' => 69,
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
                                        'value' => 'cipher',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 134,
                                        'char' => 84,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 134,
                                      'char' => 84,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 134,
                                  'char' => 85,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 134,
                                'char' => 85,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 134,
                              'char' => 85,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 134,
                          'char' => 86,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 134,
                        'char' => 86,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 134,
                    'char' => 87,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 134,
                  'char' => 87,
                ),
                2 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'authData',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 135,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'authData',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 135,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 135,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 135,
                  'char' => 38,
                ),
                3 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'authTag',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 136,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'authTag',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 136,
                      'char' => 37,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 136,
                    'char' => 37,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 136,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 138,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 138,
                  'char' => 14,
                ),
                'name' => 'assertCipherIsAvailable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 138,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 138,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 138,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 140,
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
                  'variable' => 'ivLength',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 140,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ivLength',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 140,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 140,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 140,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 142,
              'char' => 10,
            ),
            6 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'ivLength',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 142,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 142,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 142,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 142,
                'char' => 32,
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
                      'variable' => 'blockSize',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ivLength',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 143,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 143,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 144,
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
                      'variable' => 'blockSize',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 145,
                          'char' => 34,
                        ),
                        'name' => 'getIvLength',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_ireplace',
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
                                      'value' => '-',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 145,
                                      'char' => 62,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'mode',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 145,
                                      'char' => 68,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 145,
                                    'char' => 68,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 145,
                                  'char' => 68,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 145,
                                    'char' => 70,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 145,
                                  'char' => 70,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'cipher',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 145,
                                    'char' => 78,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 145,
                                  'char' => 78,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 145,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 145,
                            'char' => 79,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 145,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 145,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 146,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 148,
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
                  'variable' => 'iv',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_substr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 148,
                          'char' => 32,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 148,
                        'char' => 32,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'int',
                          'value' => '0',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 148,
                          'char' => 35,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 148,
                        'char' => 35,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ivLength',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 148,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 148,
                        'char' => 45,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '8bit',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 148,
                          'char' => 51,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 148,
                        'char' => 51,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 148,
                    'char' => 52,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 148,
                  'char' => 52,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 150,
              'char' => 10,
            ),
            8 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 150,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'useSigning',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 150,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 150,
                'char' => 29,
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
                      'variable' => 'hashAlgo',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 151,
                          'char' => 35,
                        ),
                        'name' => 'getHashAlgo',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 151,
                        'char' => 49,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 151,
                      'char' => 49,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'hashLength',
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
                              'type' => 'fcall',
                              'name' => 'hash',
                              'call-type' => 1,
                              'parameters' => 
                              array (
                                0 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'hashAlgo',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 152,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 152,
                                  'char' => 50,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 152,
                                    'char' => 52,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 152,
                                  'char' => 52,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'bool',
                                    'value' => 'true',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 152,
                                    'char' => 58,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 152,
                                  'char' => 58,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 152,
                              'char' => 59,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 152,
                            'char' => 59,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 152,
                        'char' => 60,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 152,
                      'char' => 60,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'hash',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 153,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 153,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ivLength',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 153,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 153,
                            'char' => 54,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'hashLength',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 153,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 153,
                            'char' => 66,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '8bit',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 153,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 153,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 153,
                        'char' => 73,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 153,
                      'char' => 73,
                    ),
                    3 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'ciphertext',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'mb_substr',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 154,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 154,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'add',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'ivLength',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 154,
                                'char' => 55,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'hashLength',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 154,
                                'char' => 67,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 154,
                              'char' => 67,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 154,
                            'char' => 67,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'null',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 154,
                              'char' => 73,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 154,
                            'char' => 73,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => '8bit',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 154,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 154,
                            'char' => 79,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 154,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 154,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 156,
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
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '-gcm',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 24,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mode',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 32,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 156,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'identical',
                          'left' => 
                          array (
                            'type' => 'string',
                            'value' => '-ccm',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 41,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'mode',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 47,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 156,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 156,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 156,
                      'char' => 50,
                    ),
                    'right' => 
                    array (
                      'type' => 'not',
                      'left' => 
                      array (
                        'type' => 'empty',
                        'left' => 
                        array (
                          'type' => 'property-access',
                          'left' => 
                          array (
                            'type' => 'variable',
                            'value' => 'this',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 64,
                          ),
                          'right' => 
                          array (
                            'type' => 'variable',
                            'value' => 'authData',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 156,
                            'char' => 74,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 156,
                          'char' => 74,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 156,
                        'char' => 74,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 156,
                      'char' => 74,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 156,
                    'char' => 74,
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
                          'variable' => 'decrypted',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'openssl_decrypt',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ciphertext',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 158,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 158,
                                'char' => 31,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'cipher',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 159,
                                  'char' => 27,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 159,
                                'char' => 27,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'decryptKey',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 160,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 160,
                                'char' => 31,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'constant',
                                  'value' => 'OPENSSL_RAW_DATA',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 161,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 161,
                                'char' => 37,
                              ),
                              4 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'iv',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 162,
                                  'char' => 23,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 162,
                                'char' => 23,
                              ),
                              5 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'authTag',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 163,
                                  'char' => 28,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 163,
                                'char' => 28,
                              ),
                              6 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'authData',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 165,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 165,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 165,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 165,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 166,
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
                          'variable' => 'decrypted',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'openssl_decrypt',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'ciphertext',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 168,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 168,
                                'char' => 31,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'cipher',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 169,
                                  'char' => 27,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 169,
                                'char' => 27,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'decryptKey',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 170,
                                  'char' => 31,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 170,
                                'char' => 31,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'constant',
                                  'value' => 'OPENSSL_RAW_DATA',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 171,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 171,
                                'char' => 37,
                              ),
                              4 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'iv',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 173,
                                  'char' => 17,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 173,
                                'char' => 17,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 173,
                            'char' => 18,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 173,
                          'char' => 18,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 174,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 176,
                  'char' => 14,
                ),
                2 => 
                array (
                  'type' => 'if',
                  'expr' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 176,
                        'char' => 22,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '-cbc',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 176,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 176,
                      'char' => 30,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 176,
                        'char' => 38,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '-ecb',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 176,
                        'char' => 45,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 176,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 176,
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
                          'operator' => 'assign',
                          'variable' => 'decrypted',
                          'expr' => 
                          array (
                            'type' => 'mcall',
                            'variable' => 
                            array (
                              'type' => 'variable',
                              'value' => 'this',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 177,
                              'char' => 38,
                            ),
                            'name' => 'cryptUnpadText',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'decrypted',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 177,
                                  'char' => 63,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 177,
                                'char' => 63,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'mode',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 177,
                                  'char' => 69,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 177,
                                'char' => 69,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'blockSize',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 177,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 177,
                                'char' => 80,
                              ),
                              3 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'property-access',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'this',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 177,
                                    'char' => 87,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'padding',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 177,
                                    'char' => 95,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 177,
                                  'char' => 95,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 177,
                                'char' => 95,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 177,
                            'char' => 96,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 177,
                          'char' => 96,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 178,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 183,
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
                      'type' => 'not-identical',
                      'left' => 
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
                              'value' => 'hashAlgo',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 183,
                              'char' => 43,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 183,
                            'char' => 43,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decrypted',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 183,
                              'char' => 54,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 183,
                            'char' => 54,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 183,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 183,
                            'char' => 66,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 183,
                              'char' => 72,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 183,
                            'char' => 72,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 183,
                        'char' => 76,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'hash',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 183,
                        'char' => 83,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 183,
                      'char' => 83,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 183,
                    'char' => 83,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'throw',
                      'expr' => 
                      array (
                        'type' => 'new',
                        'class' => 'Mismatch',
                        'dynamic' => 0,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'string',
                              'value' => 'Hash does not match.',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 184,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 184,
                            'char' => 56,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 184,
                        'char' => 57,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 185,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 187,
                  'char' => 18,
                ),
                4 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'decrypted',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 187,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 188,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 190,
              'char' => 11,
            ),
            9 => 
            array (
              'type' => 'let',
              'assignments' => 
              array (
                0 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'ciphertext',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'mb_substr',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'text',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 190,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 190,
                        'char' => 40,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ivLength',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 190,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 190,
                        'char' => 50,
                      ),
                      2 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'null',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 190,
                          'char' => 56,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 190,
                        'char' => 56,
                      ),
                      3 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '8bit',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 190,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 190,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 190,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 190,
                  'char' => 63,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 192,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '-gcm',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 192,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '-ccm',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 192,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 192,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 192,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'authData',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 192,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 192,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 192,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 192,
                  'char' => 70,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 192,
                'char' => 70,
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
                      'variable' => 'decrypted',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'openssl_decrypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ciphertext',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 194,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 194,
                            'char' => 27,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'cipher',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 195,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 195,
                            'char' => 23,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 196,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 196,
                            'char' => 27,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'OPENSSL_RAW_DATA',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 197,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 197,
                            'char' => 33,
                          ),
                          4 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'iv',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 198,
                              'char' => 19,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 198,
                            'char' => 19,
                          ),
                          5 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'authTag',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 199,
                              'char' => 24,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 199,
                            'char' => 24,
                          ),
                          6 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'authData',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 201,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 201,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 201,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 201,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 202,
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
                      'variable' => 'decrypted',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'openssl_decrypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ciphertext',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 204,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 204,
                            'char' => 27,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'cipher',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 205,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 205,
                            'char' => 23,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 206,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 206,
                            'char' => 27,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'OPENSSL_RAW_DATA',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 207,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 207,
                            'char' => 33,
                          ),
                          4 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'iv',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 209,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 209,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 209,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 209,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 210,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 212,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 212,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '-cbc',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 212,
                    'char' => 26,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 212,
                  'char' => 26,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 212,
                    'char' => 34,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => '-ecb',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 212,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 212,
                  'char' => 41,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 212,
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
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'decrypted',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 213,
                          'char' => 34,
                        ),
                        'name' => 'cryptUnpadText',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'decrypted',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 214,
                              'char' => 26,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 214,
                            'char' => 26,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'mode',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 215,
                              'char' => 21,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 215,
                            'char' => 21,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'blockSize',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 216,
                              'char' => 26,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 216,
                            'char' => 26,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'property-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'this',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 217,
                                'char' => 22,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'padding',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 218,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 218,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 218,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 218,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 218,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 219,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 221,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'decrypted',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 221,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 222,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decrypts an encrypted text.
     *
     * ```php
     * $encrypted = $crypt->decrypt(
     *     $encrypted,
     *     "T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3"
     * );
     * ```
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 119,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 119,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 118,
          'last-line' => 228,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'decryptBase64',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 229,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 229,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 229,
              'char' => 59,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'safe',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 229,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 229,
              'char' => 79,
            ),
          ),
          'statements' => 
          array (
            0 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'safe',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 231,
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
                      'variable' => 'text',
                      'expr' => 
                      array (
                        'type' => 'concat',
                        'left' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strtr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'text',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 232,
                                'char' => 34,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 232,
                              'char' => 34,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '-_',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 232,
                                'char' => 38,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 232,
                              'char' => 38,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '+/',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 232,
                                'char' => 42,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 232,
                              'char' => 42,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 232,
                          'char' => 44,
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
                                'type' => 'string',
                                'value' => '===',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 232,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 232,
                              'char' => 56,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'mod',
                                'left' => 
                                array (
                                  'type' => 'list',
                                  'left' => 
                                  array (
                                    'type' => 'add',
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
                                            'value' => 'text',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 232,
                                            'char' => 70,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 232,
                                          'char' => 70,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 232,
                                      'char' => 72,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '3',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 232,
                                      'char' => 75,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 232,
                                    'char' => 75,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 232,
                                  'char' => 77,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '4',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 232,
                                  'char' => 80,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 232,
                                'char' => 80,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 232,
                              'char' => 80,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 232,
                          'char' => 81,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 232,
                        'char' => 81,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 232,
                      'char' => 81,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 233,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 235,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'mcall',
                'variable' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 235,
                  'char' => 21,
                ),
                'name' => 'decrypt',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'fcall',
                      'name' => 'base64_decode',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 236,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 236,
                          'char' => 31,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 236,
                      'char' => 32,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 236,
                    'char' => 32,
                  ),
                  1 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'key',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 238,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 238,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 238,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 239,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Decrypt a text that is coded as a base64 string.
     *
     * @throws \\Phalcon\\Crypt\\Mismatch
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 230,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 230,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 229,
          'last-line' => 250,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'encrypt',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 251,
              'char' => 41,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 251,
                'char' => 61,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 251,
              'char' => 61,
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
                  'variable' => 'authData',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 21,
                ),
                1 => 
                array (
                  'variable' => 'authTag',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 30,
                ),
                2 => 
                array (
                  'variable' => 'authTagLength',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 45,
                ),
                3 => 
                array (
                  'variable' => 'encryptKey',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 57,
                ),
                4 => 
                array (
                  'variable' => 'ivLength',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 67,
                ),
                5 => 
                array (
                  'variable' => 'iv',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 253,
                  'char' => 71,
                ),
                6 => 
                array (
                  'variable' => 'cipher',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 19,
                ),
                7 => 
                array (
                  'variable' => 'mode',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 25,
                ),
                8 => 
                array (
                  'variable' => 'blockSize',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 36,
                ),
                9 => 
                array (
                  'variable' => 'paddingType',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 49,
                ),
                10 => 
                array (
                  'variable' => 'padded',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 57,
                ),
                11 => 
                array (
                  'variable' => 'encrypted',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 254,
                  'char' => 68,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 256,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 256,
                    'char' => 29,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 256,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 256,
                'char' => 29,
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
                      'variable' => 'encryptKey',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 257,
                          'char' => 35,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'key',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 257,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 257,
                        'char' => 39,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 257,
                      'char' => 39,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 258,
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
                      'variable' => 'encryptKey',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'key',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 259,
                        'char' => 33,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 259,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 260,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 262,
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
                  'type' => 'empty',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'encryptKey',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 262,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 262,
                  'char' => 38,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 262,
                'char' => 38,
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
                          'value' => 'Encryption key cannot be empty',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 263,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 263,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 263,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 264,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 266,
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
                  'variable' => 'cipher',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 266,
                      'char' => 27,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 266,
                      'char' => 34,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 266,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 266,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 268,
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
                  'variable' => 'mode',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'strtolower',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
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
                                'value' => 'cipher',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 270,
                                'char' => 23,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 270,
                              'char' => 23,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'strrpos',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'cipher',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 271,
                                        'char' => 31,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 271,
                                      'char' => 31,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'string',
                                        'value' => '-',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 271,
                                        'char' => 34,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 271,
                                      'char' => 34,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 271,
                                  'char' => 36,
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
                                        'value' => 'cipher',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 271,
                                        'char' => 51,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 271,
                                      'char' => 51,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 272,
                                  'char' => 13,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 272,
                                'char' => 13,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 272,
                              'char' => 13,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 273,
                          'char' => 9,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 273,
                        'char' => 9,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 273,
                    'char' => 10,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 273,
                  'char' => 10,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 275,
              'char' => 12,
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
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 275,
                  'char' => 14,
                ),
                'name' => 'assertCipherIsAvailable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 275,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 275,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 275,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 277,
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
                  'variable' => 'ivLength',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 277,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'ivLength',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 277,
                      'char' => 38,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 277,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 277,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 279,
              'char' => 10,
            ),
            7 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'ivLength',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 279,
                    'char' => 28,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 279,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 279,
                  'char' => 32,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 279,
                'char' => 32,
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
                      'variable' => 'blockSize',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'ivLength',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 280,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 280,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 281,
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
                      'variable' => 'blockSize',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 282,
                          'char' => 34,
                        ),
                        'name' => 'getIvLength',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'fcall',
                              'name' => 'str_ireplace',
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
                                      'value' => '-',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 284,
                                      'char' => 23,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'mode',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 284,
                                      'char' => 29,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 284,
                                    'char' => 29,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 284,
                                  'char' => 29,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => '',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 285,
                                    'char' => 21,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 285,
                                  'char' => 21,
                                ),
                                2 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'cipher',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 287,
                                    'char' => 17,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 287,
                                  'char' => 17,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 288,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 288,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 288,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 288,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 289,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 291,
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
                  'variable' => 'iv',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'openssl_random_pseudo_bytes',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'ivLength',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 291,
                          'char' => 63,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 291,
                        'char' => 63,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 291,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 291,
                  'char' => 64,
                ),
                1 => 
                array (
                  'assign-type' => 'variable',
                  'operator' => 'assign',
                  'variable' => 'paddingType',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 292,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'padding',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 292,
                      'char' => 40,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 292,
                    'char' => 40,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 292,
                  'char' => 40,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 294,
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
                  'type' => 'not-equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paddingType',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 294,
                    'char' => 25,
                  ),
                  'right' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 294,
                    'char' => 30,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 294,
                  'char' => 30,
                ),
                'right' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 294,
                        'char' => 39,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '-cbc',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 294,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 294,
                      'char' => 47,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 294,
                        'char' => 55,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => '-ecb',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 294,
                        'char' => 61,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 294,
                      'char' => 61,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 294,
                    'char' => 61,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 294,
                  'char' => 63,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 294,
                'char' => 63,
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
                      'variable' => 'padded',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 295,
                          'char' => 31,
                        ),
                        'name' => 'cryptPadText',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'text',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 295,
                              'char' => 49,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 295,
                            'char' => 49,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'mode',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 295,
                              'char' => 55,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 295,
                            'char' => 55,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'blockSize',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 295,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 295,
                            'char' => 66,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'paddingType',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 295,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 295,
                            'char' => 79,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 295,
                        'char' => 80,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 295,
                      'char' => 80,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 296,
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
                      'variable' => 'padded',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'text',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 297,
                        'char' => 30,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 297,
                      'char' => 30,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 298,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 304,
              'char' => 10,
            ),
            10 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'and',
                'left' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '-gcm',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 20,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 28,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 304,
                      'char' => 28,
                    ),
                    'right' => 
                    array (
                      'type' => 'identical',
                      'left' => 
                      array (
                        'type' => 'string',
                        'value' => '-ccm',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 304,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 304,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 304,
                  'char' => 46,
                ),
                'right' => 
                array (
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'empty',
                    'left' => 
                    array (
                      'type' => 'property-access',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'this',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 60,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'authData',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 304,
                        'char' => 70,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 304,
                      'char' => 70,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 304,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 304,
                  'char' => 70,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 304,
                'char' => 70,
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
                      'variable' => 'authData',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 305,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'authData',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 305,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 305,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 305,
                      'char' => 47,
                    ),
                    1 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'authTag',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 306,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'authTag',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 306,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 306,
                        'char' => 46,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 306,
                      'char' => 46,
                    ),
                    2 => 
                    array (
                      'assign-type' => 'variable',
                      'operator' => 'assign',
                      'variable' => 'authTagLength',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 307,
                          'char' => 38,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'authTagLength',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 307,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 307,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 307,
                      'char' => 52,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 309,
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
                      'variable' => 'encrypted',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'openssl_encrypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'padded',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 310,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 310,
                            'char' => 23,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'cipher',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 311,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 311,
                            'char' => 23,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'encryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 312,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 312,
                            'char' => 27,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'OPENSSL_RAW_DATA',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 313,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 313,
                            'char' => 33,
                          ),
                          4 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'iv',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 314,
                              'char' => 19,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 314,
                            'char' => 19,
                          ),
                          5 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'authTag',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 315,
                              'char' => 24,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 315,
                            'char' => 24,
                          ),
                          6 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'authData',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 316,
                              'char' => 25,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 316,
                            'char' => 25,
                          ),
                          7 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'authTagLength',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 318,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 318,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 318,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 318,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 320,
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
                      'property' => 'authTag',
                      'expr' => 
                      array (
                        'type' => 'variable',
                        'value' => 'authTag',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 320,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 320,
                      'char' => 40,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 321,
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
                      'variable' => 'encrypted',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'openssl_encrypt',
                        'call-type' => 1,
                        'parameters' => 
                        array (
                          0 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'padded',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 323,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 323,
                            'char' => 23,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'cipher',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 324,
                              'char' => 23,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 324,
                            'char' => 23,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'encryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 325,
                              'char' => 27,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 325,
                            'char' => 27,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'constant',
                              'value' => 'OPENSSL_RAW_DATA',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 326,
                              'char' => 33,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 326,
                            'char' => 33,
                          ),
                          4 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'iv',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 328,
                              'char' => 13,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 328,
                            'char' => 13,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 328,
                        'char' => 14,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 328,
                      'char' => 14,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 329,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 331,
              'char' => 10,
            ),
            11 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'property-access',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'this',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 331,
                  'char' => 17,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'useSigning',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 331,
                  'char' => 29,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 331,
                'char' => 29,
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
                      'variable' => 'digest',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 332,
                      'char' => 23,
                    ),
                    1 => 
                    array (
                      'variable' => 'hashAlgo',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 332,
                      'char' => 33,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 334,
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
                      'variable' => 'hashAlgo',
                      'expr' => 
                      array (
                        'type' => 'mcall',
                        'variable' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 334,
                          'char' => 33,
                        ),
                        'name' => 'getHashAlgo',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 334,
                        'char' => 47,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 334,
                      'char' => 47,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 335,
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
                      'variable' => 'digest',
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
                              'value' => 'hashAlgo',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 335,
                              'char' => 44,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 335,
                            'char' => 44,
                          ),
                          1 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'padded',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 335,
                              'char' => 52,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 335,
                            'char' => 52,
                          ),
                          2 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'variable',
                              'value' => 'encryptKey',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 335,
                              'char' => 64,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 335,
                            'char' => 64,
                          ),
                          3 => 
                          array (
                            'parameter' => 
                            array (
                              'type' => 'bool',
                              'value' => 'true',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 335,
                              'char' => 70,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 335,
                            'char' => 70,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 335,
                        'char' => 71,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 335,
                      'char' => 71,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 337,
                  'char' => 18,
                ),
                3 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'concat',
                    'left' => 
                    array (
                      'type' => 'concat',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'iv',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 337,
                        'char' => 23,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'digest',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 337,
                        'char' => 32,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 337,
                      'char' => 32,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'encrypted',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 337,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 337,
                    'char' => 43,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 338,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 340,
              'char' => 14,
            ),
            12 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'iv',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 340,
                  'char' => 19,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'encrypted',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 340,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 340,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 341,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Encrypts a text.
     *
     * ```php
     * $encrypted = $crypt->encrypt(
     *     "Top secret",
     *     "T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3"
     * );
     * ```
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 252,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 252,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 251,
          'last-line' => 345,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'encryptBase64',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 346,
              'char' => 47,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 346,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 346,
              'char' => 59,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'safe',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 1,
              'default' => 
              array (
                'type' => 'bool',
                'value' => 'false',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 346,
                'char' => 79,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 346,
              'char' => 79,
            ),
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
                  'value' => 'safe',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 348,
                  'char' => 18,
                ),
                'right' => 
                array (
                  'type' => 'bool',
                  'value' => 'true',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 348,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 348,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'rtrim',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'strtr',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'base64_encode',
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
                                        'value' => 'this',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 352,
                                        'char' => 30,
                                      ),
                                      'name' => 'encrypt',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'text',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 352,
                                            'char' => 43,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 352,
                                          'char' => 43,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'key',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 352,
                                            'char' => 48,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 352,
                                          'char' => 48,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 353,
                                      'char' => 21,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 353,
                                    'char' => 21,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 353,
                                'char' => 22,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 353,
                              'char' => 22,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '+/',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 354,
                                'char' => 23,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 354,
                              'char' => 23,
                            ),
                            2 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => '-_',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 356,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 356,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 356,
                          'char' => 18,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 356,
                        'char' => 18,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => '=',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 358,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 358,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 358,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 359,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 361,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'base64_encode',
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
                        'value' => 'this',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 362,
                        'char' => 18,
                      ),
                      'name' => 'encrypt',
                      'call-type' => 1,
                      'parameters' => 
                      array (
                        0 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'text',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 362,
                            'char' => 31,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 362,
                          'char' => 31,
                        ),
                        1 => 
                        array (
                          'parameter' => 
                          array (
                            'type' => 'variable',
                            'value' => 'key',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 362,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 362,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 363,
                      'char' => 9,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 363,
                    'char' => 9,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 363,
                'char' => 10,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 364,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Encrypts a text returning the result as a base64 string.
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 347,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 347,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 346,
          'last-line' => 368,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAvailableCiphers',
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
                  'variable' => 'availableCiphers',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 371,
                  'char' => 29,
                ),
                1 => 
                array (
                  'variable' => 'cipher',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 371,
                  'char' => 37,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 372,
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
                  'variable' => 'allowedCiphers',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 372,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 374,
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
                  'variable' => 'availableCiphers',
                  'expr' => 
                  array (
                    'type' => 'property-access',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 374,
                      'char' => 37,
                    ),
                    'right' => 
                    array (
                      'type' => 'variable',
                      'value' => 'availableCiphers',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 374,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 374,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 374,
                  'char' => 54,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 376,
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
                  'type' => 'not-identical',
                  'left' => 
                  array (
                    'type' => 'typeof',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'availableCiphers',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 376,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 376,
                    'char' => 47,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'array',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 376,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 376,
                  'char' => 55,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 376,
                'char' => 55,
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
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 377,
                      'char' => 18,
                    ),
                    'name' => 'initializeAvailableCiphers',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 377,
                    'char' => 47,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 379,
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
                      'variable' => 'availableCiphers',
                      'expr' => 
                      array (
                        'type' => 'property-access',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'this',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 379,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'availableCiphers',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 379,
                          'char' => 58,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 379,
                        'char' => 58,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 379,
                      'char' => 58,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 380,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 382,
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
                  'variable' => 'allowedCiphers',
                  'expr' => 
                  array (
                    'type' => 'empty-array',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 382,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 382,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 383,
              'char' => 11,
            ),
            5 => 
            array (
              'type' => 'for',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'availableCiphers',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 383,
                'char' => 40,
              ),
              'value' => 'cipher',
              'reverse' => 0,
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
                      'type' => 'list',
                      'left' => 
                      array (
                        'type' => 'or',
                        'left' => 
                        array (
                          'type' => 'or',
                          'left' => 
                          array (
                            'type' => 'or',
                            'left' => 
                            array (
                              'type' => 'or',
                              'left' => 
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
                                      'type' => 'fcall',
                                      'name' => 'strtolower',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'cipher',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 384,
                                            'char' => 47,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 384,
                                          'char' => 47,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 384,
                                      'char' => 48,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 384,
                                    'char' => 48,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'des',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 384,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 384,
                                    'char' => 53,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 384,
                                'char' => 56,
                              ),
                              'right' => 
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
                                      'type' => 'fcall',
                                      'name' => 'strtolower',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'cipher',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 385,
                                            'char' => 47,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 385,
                                          'char' => 47,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 385,
                                      'char' => 48,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 385,
                                    'char' => 48,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => 'rc2',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 385,
                                      'char' => 53,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 385,
                                    'char' => 53,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 385,
                                'char' => 56,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 385,
                              'char' => 56,
                            ),
                            'right' => 
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
                                    'type' => 'fcall',
                                    'name' => 'strtolower',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'cipher',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 386,
                                          'char' => 47,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 386,
                                        'char' => 47,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 386,
                                    'char' => 48,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 386,
                                  'char' => 48,
                                ),
                                1 => 
                                array (
                                  'parameter' => 
                                  array (
                                    'type' => 'string',
                                    'value' => 'rc4',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 386,
                                    'char' => 53,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 386,
                                  'char' => 53,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 386,
                              'char' => 56,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 386,
                            'char' => 56,
                          ),
                          'right' => 
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
                                  'type' => 'fcall',
                                  'name' => 'strtolower',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'cipher',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 387,
                                        'char' => 47,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 387,
                                      'char' => 47,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 387,
                                  'char' => 48,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 387,
                                'char' => 48,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'string',
                                  'value' => 'des',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 387,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 387,
                                'char' => 53,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 387,
                            'char' => 56,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 387,
                          'char' => 56,
                        ),
                        'right' => 
                        array (
                          'type' => 'fcall',
                          'name' => 'ends_with',
                          'call-type' => 1,
                          'parameters' => 
                          array (
                            0 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'strtolower',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'cipher',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 388,
                                      'char' => 45,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 388,
                                    'char' => 45,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 388,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 388,
                              'char' => 46,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'string',
                                'value' => 'ecb',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 388,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 388,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 388,
                          'char' => 52,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 388,
                        'char' => 52,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 388,
                      'char' => 54,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 388,
                    'char' => 54,
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
                          'assign-type' => 'variable-append',
                          'operator' => 'assign',
                          'variable' => 'allowedCiphers',
                          'expr' => 
                          array (
                            'type' => 'variable',
                            'value' => 'cipher',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 389,
                            'char' => 46,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 389,
                          'char' => 46,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 390,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 391,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 393,
              'char' => 14,
            ),
            6 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'allowedCiphers',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 393,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 394,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns a list of available ciphers.
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 370,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 370,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 369,
          'last-line' => 398,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getAvailableHashAlgos',
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
                  'variable' => 'algos',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 401,
                  'char' => 18,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 403,
              'char' => 10,
            ),
            1 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'likely',
                'left' => 
                array (
                  'type' => 'fcall',
                  'name' => 'function_exists',
                  'call-type' => 1,
                  'parameters' => 
                  array (
                    0 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'string',
                        'value' => 'hash_hmac_algos',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 403,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 403,
                      'char' => 50,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 403,
                  'char' => 52,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 403,
                'char' => 52,
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
                      'variable' => 'algos',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'hash_hmac_algos',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 404,
                        'char' => 42,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 404,
                      'char' => 42,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 405,
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
                      'variable' => 'algos',
                      'expr' => 
                      array (
                        'type' => 'fcall',
                        'name' => 'hash_algos',
                        'call-type' => 1,
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 406,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 406,
                      'char' => 37,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 407,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 409,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'algos',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 409,
                'char' => 21,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 410,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Return a list of registered hashing algorithms suitable for hash_hmac.
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 400,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 400,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 399,
          'last-line' => 414,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getCipher',
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 417,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'cipher',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 417,
                  'char' => 28,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 417,
                'char' => 28,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 418,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the current cipher
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 416,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 416,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 415,
          'last-line' => 422,
          'char' => 19,
        ),
        8 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getHashAlgo',
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 425,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'hashAlgo',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 425,
                  'char' => 30,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 425,
                'char' => 30,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 426,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Get the name of hashing algorithm.
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 424,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 424,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 423,
          'last-line' => 430,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getKey',
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 433,
                  'char' => 21,
                ),
                'right' => 
                array (
                  'type' => 'variable',
                  'value' => 'key',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 433,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 433,
                'char' => 25,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 434,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Returns the encryption key
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 432,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 432,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 431,
          'last-line' => 436,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthTag',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'tag',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 436,
              'char' => 43,
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
                  'property' => 'authTag',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'tag',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 438,
                    'char' => 32,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 438,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 440,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 440,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 441,
              'char' => 5,
            ),
          ),
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 437,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 437,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 437,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 436,
          'last-line' => 443,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthData',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'data',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 443,
              'char' => 45,
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
                  'property' => 'authData',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'data',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 445,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 445,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 447,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 447,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 448,
              'char' => 5,
            ),
          ),
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 444,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 444,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 444,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 443,
          'last-line' => 450,
          'char' => 19,
        ),
        12 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setAuthTagLength',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'length',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 450,
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
                  'property' => 'authTagLength',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'length',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 452,
                    'char' => 41,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 452,
                  'char' => 41,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 454,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 454,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 455,
              'char' => 5,
            ),
          ),
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 451,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 451,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 451,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 450,
          'last-line' => 465,
          'char' => 19,
        ),
        13 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setCipher',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cipher',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 466,
              'char' => 45,
            ),
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 468,
                  'char' => 14,
                ),
                'name' => 'assertCipherIsAvailable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 468,
                      'char' => 45,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 468,
                    'char' => 45,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 468,
                'char' => 46,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 470,
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
                  'property' => 'ivLength',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 470,
                      'char' => 35,
                    ),
                    'name' => 'getIvLength',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cipher',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 470,
                          'char' => 54,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 470,
                        'char' => 54,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 470,
                    'char' => 55,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 470,
                  'char' => 55,
                ),
                1 => 
                array (
                  'assign-type' => 'object-property',
                  'operator' => 'assign',
                  'variable' => 'this',
                  'property' => 'cipher',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'cipher',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 471,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 471,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 473,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 473,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 474,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the cipher algorithm for data encryption and decryption.
     *
     * The `aes-256-gcm\' is the preferable cipher, but it is not usable
     * until the openssl library is upgraded, which is available in PHP 7.1.
     *
     * The `aes-256-ctr\' is arguably the best choice for cipher
     * algorithm for current openssl library version.
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 467,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 467,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 467,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 466,
          'last-line' => 480,
          'char' => 19,
        ),
        14 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setHashAlgo',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'hashAlgo',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 481,
              'char' => 49,
            ),
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 483,
                  'char' => 14,
                ),
                'name' => 'assertHashAlgorithmAvailable',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'hashAlgo',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 483,
                      'char' => 52,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 483,
                    'char' => 52,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 483,
                'char' => 53,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 485,
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
                  'property' => 'hashAlgo',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'hashAlgo',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 485,
                    'char' => 38,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 485,
                  'char' => 38,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 487,
              'char' => 14,
            ),
            2 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 487,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 488,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Set the name of hashing algorithm.
     *
     * @throws \\Phalcon\\Crypt\\Exception
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 482,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 482,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 482,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 481,
          'last-line' => 504,
          'char' => 19,
        ),
        15 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setKey',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'key',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 505,
              'char' => 39,
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
                  'property' => 'key',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'key',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 507,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 507,
                  'char' => 28,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 509,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 509,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 510,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets the encryption key.
     *
     * The `$key\' should have been previously generated in a cryptographically
     * safe way.
     *
     * Bad key:
     * "le password"
     *
     * Better (but still unsafe):
     * "#1dj8$=dp?.ak//j1V$~%*0X"
     *
     * Good key:
     * "T4\\xb1\\x8d\\xa9\\x98\\x05\\\\\\x8c\\xbe\\x1d\\x07&[\\x99\\x18\\xa4~Lc1\\xbeW\\xb3"
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 506,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 506,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 506,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 505,
          'last-line' => 514,
          'char' => 19,
        ),
        16 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setPadding',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'scheme',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 515,
              'char' => 43,
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
                  'property' => 'padding',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'scheme',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 517,
                    'char' => 35,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 517,
                  'char' => 35,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 519,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 519,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 520,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Changes the padding scheme used.
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 516,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 516,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 516,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 515,
          'last-line' => 524,
          'char' => 19,
        ),
        17 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'useSigning',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'useSigning',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 525,
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
                  'property' => 'useSigning',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'useSigning',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 527,
                    'char' => 42,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 527,
                  'char' => 42,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 529,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'variable',
                'value' => 'this',
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 529,
                'char' => 20,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 530,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Sets if the calculating message digest must used.
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
                  'value' => 'CryptInterface',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 526,
                  'char' => 5,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 526,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 526,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 525,
          'last-line' => 534,
          'char' => 19,
        ),
        18 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'assertCipherIsAvailable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cipher',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 535,
              'char' => 62,
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
                  'variable' => 'availableCiphers',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 537,
                  'char' => 29,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 539,
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
                  'variable' => 'availableCiphers',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 539,
                      'char' => 37,
                    ),
                    'name' => 'getAvailableCiphers',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 539,
                    'char' => 59,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 539,
                  'char' => 59,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 541,
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
                    'type' => 'fcall',
                    'name' => 'in_array',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'cipher',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 541,
                          'char' => 37,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 541,
                        'char' => 37,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'availableCiphers',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 541,
                          'char' => 55,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 541,
                        'char' => 55,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 541,
                    'char' => 57,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 541,
                  'char' => 57,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 541,
                'char' => 57,
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
                                'value' => 'The cipher algorithm \\"%s\\" is not supported on this system.',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 544,
                                'char' => 81,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 544,
                              'char' => 81,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'cipher',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 546,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 546,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 547,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 547,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 547,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 548,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 549,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assert the cipher is available.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 536,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 535,
          'last-line' => 553,
          'char' => 22,
        ),
        19 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'assertHashAlgorithmAvailable',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'hashAlgo',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 554,
              'char' => 69,
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
                  'variable' => 'availableAlgorithms',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 556,
                  'char' => 32,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 558,
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
                  'variable' => 'availableAlgorithms',
                  'expr' => 
                  array (
                    'type' => 'mcall',
                    'variable' => 
                    array (
                      'type' => 'variable',
                      'value' => 'this',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 558,
                      'char' => 40,
                    ),
                    'name' => 'getAvailableHashAlgos',
                    'call-type' => 1,
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 558,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 558,
                  'char' => 64,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 560,
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
                    'type' => 'fcall',
                    'name' => 'in_array',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'hashAlgo',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 560,
                          'char' => 39,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 560,
                        'char' => 39,
                      ),
                      1 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'variable',
                          'value' => 'availableAlgorithms',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 560,
                          'char' => 60,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 560,
                        'char' => 60,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 560,
                    'char' => 62,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 560,
                  'char' => 62,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 560,
                'char' => 62,
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
                                'value' => 'The hash algorithm \\"%s\\" is not supported on this system.',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 563,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 563,
                              'char' => 79,
                            ),
                            1 => 
                            array (
                              'parameter' => 
                              array (
                                'type' => 'variable',
                                'value' => 'hashAlgo',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 565,
                                'char' => 17,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 565,
                              'char' => 17,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 566,
                          'char' => 13,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 566,
                        'char' => 13,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 566,
                    'char' => 14,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 567,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 568,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Assert the hash algorithm is available.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 555,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 554,
          'last-line' => 572,
          'char' => 22,
        ),
        20 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'getIvLength',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'cipher',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 573,
              'char' => 50,
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
                  'type' => 'not',
                  'left' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'function_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'openssl_cipher_iv_length',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 575,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 575,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 575,
                    'char' => 64,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 575,
                  'char' => 64,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 575,
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
                          'value' => 'openssl extension is required',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 576,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 576,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 576,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 577,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 579,
              'char' => 14,
            ),
            1 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'fcall',
                'name' => 'openssl_cipher_iv_length',
                'call-type' => 1,
                'parameters' => 
                array (
                  0 => 
                  array (
                    'parameter' => 
                    array (
                      'type' => 'variable',
                      'value' => 'cipher',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 579,
                      'char' => 47,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 579,
                    'char' => 47,
                  ),
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 579,
                'char' => 48,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 580,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Initialize available cipher algorithms.
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 574,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 574,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 573,
          'last-line' => 584,
          'char' => 22,
        ),
        21 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'initializeAvailableCiphers',
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
                    'type' => 'fcall',
                    'name' => 'function_exists',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'string',
                          'value' => 'openssl_get_cipher_methods',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 587,
                          'char' => 64,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 587,
                        'char' => 64,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 587,
                    'char' => 66,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 587,
                  'char' => 66,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 587,
                'char' => 66,
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
                          'value' => 'openssl extension is required',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 588,
                          'char' => 62,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 588,
                        'char' => 62,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 588,
                    'char' => 63,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 589,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 591,
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
                  'property' => 'availableCiphers',
                  'expr' => 
                  array (
                    'type' => 'fcall',
                    'name' => 'openssl_get_cipher_methods',
                    'call-type' => 1,
                    'parameters' => 
                    array (
                      0 => 
                      array (
                        'parameter' => 
                        array (
                          'type' => 'bool',
                          'value' => 'true',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 591,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 591,
                        'char' => 69,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 591,
                    'char' => 70,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 591,
                  'char' => 70,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 592,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Initialize available cipher algorithms.
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 586,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 585,
          'last-line' => 596,
          'char' => 22,
        ),
        22 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'cryptPadText',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 597,
              'char' => 48,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 597,
              'char' => 62,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'blockSize',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 597,
              'char' => 78,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'paddingType',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 597,
              'char' => 96,
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
                  'variable' => 'i',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 599,
                  'char' => 14,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 600,
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
                  'variable' => 'paddingSize',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 600,
                    'char' => 28,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 600,
                  'char' => 28,
                ),
                1 => 
                array (
                  'variable' => 'padding',
                  'expr' => 
                  array (
                    'type' => 'null',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 600,
                    'char' => 44,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 600,
                  'char' => 44,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 602,
              'char' => 10,
            ),
            2 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'or',
                'left' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 602,
                    'char' => 18,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'cbc',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 602,
                    'char' => 25,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 602,
                  'char' => 25,
                ),
                'right' => 
                array (
                  'type' => 'equals',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'mode',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 602,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'string',
                    'value' => 'ecb',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 602,
                    'char' => 39,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 602,
                  'char' => 39,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 602,
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
                      'variable' => 'paddingSize',
                      'expr' => 
                      array (
                        'type' => 'sub',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'blockSize',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 603,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'list',
                          'left' => 
                          array (
                            'type' => 'mod',
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
                                    'value' => 'text',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 603,
                                    'char' => 55,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 603,
                                  'char' => 55,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 603,
                              'char' => 57,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'blockSize',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 603,
                              'char' => 68,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 603,
                            'char' => 68,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 603,
                          'char' => 69,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 603,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 603,
                      'char' => 69,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 605,
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
                      'type' => 'greater-equal',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paddingSize',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 605,
                        'char' => 37,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '256',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 605,
                        'char' => 43,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 605,
                      'char' => 43,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 605,
                    'char' => 43,
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
                              'value' => 'Block size is bigger than 256',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 606,
                              'char' => 66,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 606,
                            'char' => 66,
                          ),
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 606,
                        'char' => 67,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 607,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 609,
                  'char' => 18,
                ),
                2 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paddingType',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 609,
                    'char' => 32,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 611,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ANSI_X_923',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 611,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 611,
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
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'str_repeat',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'chr',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '0',
                                              'file' => '/app/phalcon/Crypt.zep',
                                              'line' => 612,
                                              'char' => 51,
                                            ),
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 612,
                                            'char' => 51,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 612,
                                        'char' => 52,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 612,
                                      'char' => 52,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'sub',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paddingSize',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 612,
                                          'char' => 66,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '1',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 612,
                                          'char' => 69,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 612,
                                        'char' => 69,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 612,
                                      'char' => 69,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 612,
                                  'char' => 71,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'chr',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'paddingSize',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 612,
                                        'char' => 88,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 612,
                                      'char' => 88,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 612,
                                  'char' => 89,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 612,
                                'char' => 89,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 612,
                              'char' => 89,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 613,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 615,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 615,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 615,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_PKCS7',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 615,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 615,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_repeat',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'chr',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'variable',
                                            'value' => 'paddingSize',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 616,
                                            'char' => 61,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 616,
                                          'char' => 61,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 616,
                                      'char' => 62,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 616,
                                    'char' => 62,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paddingSize',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 616,
                                      'char' => 75,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 616,
                                    'char' => 75,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 616,
                                'char' => 76,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 616,
                              'char' => 76,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 617,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 619,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 619,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 619,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ISO_10126',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 619,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 619,
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
                              'operator' => 'assign',
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'string',
                                'value' => '',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 620,
                                'char' => 35,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 620,
                              'char' => 35,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 622,
                          'char' => 23,
                        ),
                        1 => 
                        array (
                          'type' => 'for',
                          'expr' => 
                          array (
                            'type' => 'fcall',
                            'name' => 'range',
                            'call-type' => 1,
                            'parameters' => 
                            array (
                              0 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 622,
                                  'char' => 37,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 622,
                                'char' => 37,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'sub',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'paddingSize',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 622,
                                    'char' => 51,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '2',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 622,
                                    'char' => 54,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 622,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 622,
                                'char' => 54,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 622,
                            'char' => 56,
                          ),
                          'value' => 'i',
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
                                  'operator' => 'concat-assign',
                                  'variable' => 'padding',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'chr',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'fcall',
                                          'name' => 'rand',
                                          'call-type' => 1,
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 623,
                                          'char' => 49,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 623,
                                        'char' => 49,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 623,
                                    'char' => 50,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 623,
                                  'char' => 50,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 624,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 626,
                          'char' => 23,
                        ),
                        2 => 
                        array (
                          'type' => 'let',
                          'assignments' => 
                          array (
                            0 => 
                            array (
                              'assign-type' => 'variable',
                              'operator' => 'concat-assign',
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'chr',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paddingSize',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 626,
                                      'char' => 50,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 626,
                                    'char' => 50,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 626,
                                'char' => 51,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 626,
                              'char' => 51,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 628,
                          'char' => 25,
                        ),
                        3 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 630,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 630,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 630,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ISO_IEC_7816_4',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 630,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 630,
                        'char' => 50,
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
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'concat',
                                'left' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'chr',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0x80',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 631,
                                        'char' => 43,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 631,
                                      'char' => 43,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 631,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'str_repeat',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'fcall',
                                        'name' => 'chr',
                                        'call-type' => 1,
                                        'parameters' => 
                                        array (
                                          0 => 
                                          array (
                                            'parameter' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '0',
                                              'file' => '/app/phalcon/Crypt.zep',
                                              'line' => 631,
                                              'char' => 63,
                                            ),
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 631,
                                            'char' => 63,
                                          ),
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 631,
                                        'char' => 64,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 631,
                                      'char' => 64,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'sub',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paddingSize',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 631,
                                          'char' => 78,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'int',
                                          'value' => '1',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 631,
                                          'char' => 81,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 631,
                                        'char' => 81,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 631,
                                      'char' => 81,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 631,
                                  'char' => 82,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 631,
                                'char' => 82,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 631,
                              'char' => 82,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 632,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 634,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 634,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 634,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ZERO',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 634,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 634,
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
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_repeat',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'chr',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'int',
                                            'value' => '0',
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 635,
                                            'char' => 51,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 635,
                                          'char' => 51,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 635,
                                      'char' => 52,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 635,
                                    'char' => 52,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paddingSize',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 635,
                                      'char' => 65,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 635,
                                    'char' => 65,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 635,
                                'char' => 66,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 635,
                              'char' => 66,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 636,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 638,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 638,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 638,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_SPACE',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 638,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 638,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'padding',
                              'expr' => 
                              array (
                                'type' => 'fcall',
                                'name' => 'str_repeat',
                                'call-type' => 1,
                                'parameters' => 
                                array (
                                  0 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'string',
                                      'value' => ' ',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 639,
                                      'char' => 47,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 639,
                                    'char' => 47,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'paddingSize',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 639,
                                      'char' => 60,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 639,
                                    'char' => 60,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 639,
                                'char' => 61,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 639,
                              'char' => 61,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 640,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 642,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 642,
                      'char' => 23,
                    ),
                    6 => 
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
                              'variable' => 'paddingSize',
                              'expr' => 
                              array (
                                'type' => 'int',
                                'value' => '0',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 643,
                                'char' => 40,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 643,
                              'char' => 40,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 644,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 645,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 645,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 646,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 648,
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
                  'value' => 'paddingSize',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 648,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 648,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'text',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 649,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 650,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 652,
              'char' => 10,
            ),
            4 => 
            array (
              'type' => 'if',
              'expr' => 
              array (
                'type' => 'unlikely',
                'left' => 
                array (
                  'type' => 'greater',
                  'left' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paddingSize',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 652,
                    'char' => 33,
                  ),
                  'right' => 
                  array (
                    'type' => 'variable',
                    'value' => 'blockSize',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 652,
                    'char' => 45,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 652,
                  'char' => 45,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 652,
                'char' => 45,
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
                          'value' => 'Invalid padding size',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 653,
                          'char' => 53,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 653,
                        'char' => 53,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 653,
                    'char' => 54,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 654,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 656,
              'char' => 14,
            ),
            5 => 
            array (
              'type' => 'return',
              'expr' => 
              array (
                'type' => 'concat',
                'left' => 
                array (
                  'type' => 'variable',
                  'value' => 'text',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 656,
                  'char' => 21,
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
                        'value' => 'padding',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 656,
                        'char' => 37,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 656,
                      'char' => 37,
                    ),
                    1 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 656,
                        'char' => 40,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 656,
                      'char' => 40,
                    ),
                    2 => 
                    array (
                      'parameter' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paddingSize',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 656,
                        'char' => 53,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 656,
                      'char' => 53,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 656,
                  'char' => 54,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 656,
                'char' => 54,
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 657,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Pads texts before encryption. See [cryptopad](http://www.di-mgt.com.au/cryptopad.html)
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
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 598,
                'char' => 5,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 598,
            'char' => 5,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 597,
          'last-line' => 664,
          'char' => 22,
        ),
        23 => 
        array (
          'visibility' => 
          array (
            0 => 'protected',
          ),
          'type' => 'method',
          'name' => 'cryptUnpadText',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'text',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 665,
              'char' => 50,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'mode',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 665,
              'char' => 64,
            ),
            2 => 
            array (
              'type' => 'parameter',
              'name' => 'blockSize',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 665,
              'char' => 80,
            ),
            3 => 
            array (
              'type' => 'parameter',
              'name' => 'paddingType',
              'const' => 0,
              'data-type' => 'int',
              'mandatory' => 1,
              'reference' => 0,
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 665,
              'char' => 98,
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
                  'variable' => 'padding',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 667,
                  'char' => 20,
                ),
                1 => 
                array (
                  'variable' => 'last',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 667,
                  'char' => 26,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 668,
              'char' => 12,
            ),
            1 => 
            array (
              'type' => 'declare',
              'data-type' => 'long',
              'variables' => 
              array (
                0 => 
                array (
                  'variable' => 'length',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 668,
                  'char' => 20,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 669,
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
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 669,
                  'char' => 14,
                ),
                1 => 
                array (
                  'variable' => 'paddingSize',
                  'expr' => 
                  array (
                    'type' => 'int',
                    'value' => '0',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 669,
                    'char' => 31,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 669,
                  'char' => 31,
                ),
                2 => 
                array (
                  'variable' => 'ord',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 669,
                  'char' => 36,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 671,
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
                  'variable' => 'length',
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
                          'value' => 'text',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 671,
                          'char' => 33,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 671,
                        'char' => 33,
                      ),
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 671,
                    'char' => 34,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 671,
                  'char' => 34,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 673,
              'char' => 10,
            ),
            4 => 
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
                    'type' => 'greater',
                    'left' => 
                    array (
                      'type' => 'variable',
                      'value' => 'length',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 673,
                      'char' => 19,
                    ),
                    'right' => 
                    array (
                      'type' => 'int',
                      'value' => '0',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 673,
                      'char' => 24,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 673,
                    'char' => 24,
                  ),
                  'right' => 
                  array (
                    'type' => 'list',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'mod',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 673,
                          'char' => 34,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'blockSize',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 673,
                          'char' => 47,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 47,
                      ),
                      'right' => 
                      array (
                        'type' => 'int',
                        'value' => '0',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 50,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 673,
                      'char' => 50,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 673,
                    'char' => 53,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 673,
                  'char' => 53,
                ),
                'right' => 
                array (
                  'type' => 'list',
                  'left' => 
                  array (
                    'type' => 'or',
                    'left' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 62,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'cbc',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 69,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 673,
                      'char' => 69,
                    ),
                    'right' => 
                    array (
                      'type' => 'equals',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'mode',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 77,
                      ),
                      'right' => 
                      array (
                        'type' => 'string',
                        'value' => 'ecb',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 673,
                        'char' => 82,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 673,
                      'char' => 82,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 673,
                    'char' => 82,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 673,
                  'char' => 84,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 673,
                'char' => 84,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'switch',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'paddingType',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 674,
                    'char' => 32,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 676,
                          'char' => 46,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ANSI_X_923',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 676,
                          'char' => 46,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 676,
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
                              'variable' => 'last',
                              'expr' => 
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
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 677,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 677,
                                    'char' => 43,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'sub',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'length',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 677,
                                        'char' => 52,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 677,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 677,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 677,
                                    'char' => 55,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 677,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 677,
                                    'char' => 58,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 677,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 677,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 678,
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
                              'variable' => 'ord',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'int',
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'ord',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'last',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 678,
                                        'char' => 45,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 678,
                                      'char' => 45,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 678,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 678,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 678,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 680,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'less-equal',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ord',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 680,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'blockSize',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 680,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 680,
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
                                  'variable' => 'paddingSize',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ord',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 681,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 681,
                                  'char' => 46,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 682,
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
                                  'variable' => 'padding',
                                  'expr' => 
                                  array (
                                    'type' => 'concat',
                                    'left' => 
                                    array (
                                      'type' => 'fcall',
                                      'name' => 'str_repeat',
                                      'call-type' => 1,
                                      'parameters' => 
                                      array (
                                        0 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'fcall',
                                            'name' => 'chr',
                                            'call-type' => 1,
                                            'parameters' => 
                                            array (
                                              0 => 
                                              array (
                                                'parameter' => 
                                                array (
                                                  'type' => 'int',
                                                  'value' => '0',
                                                  'file' => '/app/phalcon/Crypt.zep',
                                                  'line' => 682,
                                                  'char' => 55,
                                                ),
                                                'file' => '/app/phalcon/Crypt.zep',
                                                'line' => 682,
                                                'char' => 55,
                                              ),
                                            ),
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 682,
                                            'char' => 56,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 682,
                                          'char' => 56,
                                        ),
                                        1 => 
                                        array (
                                          'parameter' => 
                                          array (
                                            'type' => 'sub',
                                            'left' => 
                                            array (
                                              'type' => 'variable',
                                              'value' => 'paddingSize',
                                              'file' => '/app/phalcon/Crypt.zep',
                                              'line' => 682,
                                              'char' => 70,
                                            ),
                                            'right' => 
                                            array (
                                              'type' => 'int',
                                              'value' => '1',
                                              'file' => '/app/phalcon/Crypt.zep',
                                              'line' => 682,
                                              'char' => 73,
                                            ),
                                            'file' => '/app/phalcon/Crypt.zep',
                                            'line' => 682,
                                            'char' => 73,
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 682,
                                          'char' => 73,
                                        ),
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 682,
                                      'char' => 75,
                                    ),
                                    'right' => 
                                    array (
                                      'type' => 'variable',
                                      'value' => 'last',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 682,
                                      'char' => 81,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 682,
                                    'char' => 81,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 682,
                                  'char' => 81,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 684,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'not-equals',
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
                                        'value' => 'text',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 684,
                                        'char' => 39,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 684,
                                      'char' => 39,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'sub',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'length',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 684,
                                          'char' => 48,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paddingSize',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 684,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 684,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 684,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 684,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'padding',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 684,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 684,
                                'char' => 74,
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
                                      'variable' => 'paddingSize',
                                      'expr' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 685,
                                        'char' => 48,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 685,
                                      'char' => 48,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 686,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 687,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 689,
                          'char' => 25,
                        ),
                        3 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 691,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 691,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 691,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_PKCS7',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 691,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 691,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'last',
                              'expr' => 
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
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 692,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 692,
                                    'char' => 43,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'sub',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'length',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 692,
                                        'char' => 52,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 692,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 692,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 692,
                                    'char' => 55,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 692,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 692,
                                    'char' => 58,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 692,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 692,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 693,
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
                              'variable' => 'ord',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'int',
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'ord',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'last',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 693,
                                        'char' => 45,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 693,
                                      'char' => 45,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 693,
                                  'char' => 46,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 693,
                                'char' => 46,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 693,
                              'char' => 46,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 695,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'less-equal',
                            'left' => 
                            array (
                              'type' => 'variable',
                              'value' => 'ord',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 695,
                              'char' => 28,
                            ),
                            'right' => 
                            array (
                              'type' => 'variable',
                              'value' => 'blockSize',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 695,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 695,
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
                                  'variable' => 'paddingSize',
                                  'expr' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'ord',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 696,
                                    'char' => 46,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 696,
                                  'char' => 46,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 697,
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
                                  'variable' => 'padding',
                                  'expr' => 
                                  array (
                                    'type' => 'fcall',
                                    'name' => 'str_repeat',
                                    'call-type' => 1,
                                    'parameters' => 
                                    array (
                                      0 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'fcall',
                                          'name' => 'chr',
                                          'call-type' => 1,
                                          'parameters' => 
                                          array (
                                            0 => 
                                            array (
                                              'parameter' => 
                                              array (
                                                'type' => 'variable',
                                                'value' => 'paddingSize',
                                                'file' => '/app/phalcon/Crypt.zep',
                                                'line' => 697,
                                                'char' => 65,
                                              ),
                                              'file' => '/app/phalcon/Crypt.zep',
                                              'line' => 697,
                                              'char' => 65,
                                            ),
                                          ),
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 697,
                                          'char' => 66,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 697,
                                        'char' => 66,
                                      ),
                                      1 => 
                                      array (
                                        'parameter' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paddingSize',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 697,
                                          'char' => 79,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 697,
                                        'char' => 79,
                                      ),
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 697,
                                    'char' => 80,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 697,
                                  'char' => 80,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 699,
                              'char' => 26,
                            ),
                            2 => 
                            array (
                              'type' => 'if',
                              'expr' => 
                              array (
                                'type' => 'not-equals',
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
                                        'value' => 'text',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 699,
                                        'char' => 39,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 699,
                                      'char' => 39,
                                    ),
                                    1 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'sub',
                                        'left' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'length',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 699,
                                          'char' => 48,
                                        ),
                                        'right' => 
                                        array (
                                          'type' => 'variable',
                                          'value' => 'paddingSize',
                                          'file' => '/app/phalcon/Crypt.zep',
                                          'line' => 699,
                                          'char' => 61,
                                        ),
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 699,
                                        'char' => 61,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 699,
                                      'char' => 61,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 699,
                                  'char' => 64,
                                ),
                                'right' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'padding',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 699,
                                  'char' => 74,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 699,
                                'char' => 74,
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
                                      'variable' => 'paddingSize',
                                      'expr' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '0',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 700,
                                        'char' => 48,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 700,
                                      'char' => 48,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 701,
                                  'char' => 25,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 702,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 704,
                          'char' => 25,
                        ),
                        3 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 706,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 706,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 706,
                          'char' => 45,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ISO_10126',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 706,
                          'char' => 45,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 706,
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
                              'operator' => 'assign',
                              'variable' => 'last',
                              'expr' => 
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
                                      'value' => 'text',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 707,
                                      'char' => 43,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 707,
                                    'char' => 43,
                                  ),
                                  1 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'sub',
                                      'left' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'length',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 707,
                                        'char' => 52,
                                      ),
                                      'right' => 
                                      array (
                                        'type' => 'int',
                                        'value' => '1',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 707,
                                        'char' => 55,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 707,
                                      'char' => 55,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 707,
                                    'char' => 55,
                                  ),
                                  2 => 
                                  array (
                                    'parameter' => 
                                    array (
                                      'type' => 'int',
                                      'value' => '1',
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 707,
                                      'char' => 58,
                                    ),
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 707,
                                    'char' => 58,
                                  ),
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 707,
                                'char' => 59,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 707,
                              'char' => 59,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 708,
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
                              'variable' => 'paddingSize',
                              'expr' => 
                              array (
                                'type' => 'cast',
                                'left' => 'int',
                                'right' => 
                                array (
                                  'type' => 'fcall',
                                  'name' => 'ord',
                                  'call-type' => 1,
                                  'parameters' => 
                                  array (
                                    0 => 
                                    array (
                                      'parameter' => 
                                      array (
                                        'type' => 'variable',
                                        'value' => 'last',
                                        'file' => '/app/phalcon/Crypt.zep',
                                        'line' => 708,
                                        'char' => 53,
                                      ),
                                      'file' => '/app/phalcon/Crypt.zep',
                                      'line' => 708,
                                      'char' => 53,
                                    ),
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 708,
                                  'char' => 54,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 708,
                                'char' => 54,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 708,
                              'char' => 54,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 709,
                          'char' => 25,
                        ),
                        2 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 711,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 711,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 711,
                          'char' => 50,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ISO_IEC_7816_4',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 711,
                          'char' => 50,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 711,
                        'char' => 50,
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
                              'variable' => 'i',
                              'expr' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'length',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 712,
                                  'char' => 36,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 712,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 712,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 712,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 714,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'while',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'and',
                              'left' => 
                              array (
                                'type' => 'greater',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 714,
                                  'char' => 29,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 714,
                                  'char' => 34,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 714,
                                'char' => 34,
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
                                    'value' => 'text',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 714,
                                    'char' => 40,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'i',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 714,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 714,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0x00',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 714,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 714,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 714,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'less',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'paddingSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 714,
                                'char' => 67,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blockSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 714,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 714,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 714,
                            'char' => 79,
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
                                  'assign-type' => 'incr',
                                  'variable' => 'paddingSize',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 715,
                                  'char' => 42,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'decr',
                                  'variable' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 716,
                                  'char' => 32,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 717,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 719,
                          'char' => 22,
                        ),
                        2 => 
                        array (
                          'type' => 'if',
                          'expr' => 
                          array (
                            'type' => 'equals',
                            'left' => 
                            array (
                              'type' => 'array-access',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'text',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 719,
                                'char' => 28,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'i',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 719,
                                'char' => 30,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 719,
                              'char' => 33,
                            ),
                            'right' => 
                            array (
                              'type' => 'int',
                              'value' => '0x80',
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 719,
                              'char' => 40,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 719,
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
                                  'assign-type' => 'incr',
                                  'variable' => 'paddingSize',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 720,
                                  'char' => 42,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 721,
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
                                  'variable' => 'paddingSize',
                                  'expr' => 
                                  array (
                                    'type' => 'int',
                                    'value' => '0',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 722,
                                    'char' => 44,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 722,
                                  'char' => 44,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 723,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 725,
                          'char' => 25,
                        ),
                        3 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 727,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 727,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 727,
                          'char' => 40,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_ZERO',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 727,
                          'char' => 40,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 727,
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
                              'variable' => 'i',
                              'expr' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'length',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 728,
                                  'char' => 36,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 728,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 728,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 728,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 730,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'while',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'and',
                              'left' => 
                              array (
                                'type' => 'greater-equal',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 730,
                                  'char' => 29,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 730,
                                  'char' => 34,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 730,
                                'char' => 34,
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
                                    'value' => 'text',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 730,
                                    'char' => 40,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'i',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 730,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 730,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0x00',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 730,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 730,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 730,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'less-equal',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'paddingSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 730,
                                'char' => 67,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blockSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 730,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 730,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 730,
                            'char' => 79,
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
                                  'assign-type' => 'incr',
                                  'variable' => 'paddingSize',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 731,
                                  'char' => 42,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'decr',
                                  'variable' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 732,
                                  'char' => 32,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 733,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 735,
                          'char' => 25,
                        ),
                        2 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 737,
                          'char' => 20,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 737,
                      'char' => 20,
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
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 737,
                          'char' => 41,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'PADDING_SPACE',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 737,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 737,
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
                              'assign-type' => 'variable',
                              'operator' => 'assign',
                              'variable' => 'i',
                              'expr' => 
                              array (
                                'type' => 'sub',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'length',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 738,
                                  'char' => 36,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '1',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 738,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 738,
                                'char' => 39,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 738,
                              'char' => 39,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 740,
                          'char' => 25,
                        ),
                        1 => 
                        array (
                          'type' => 'while',
                          'expr' => 
                          array (
                            'type' => 'and',
                            'left' => 
                            array (
                              'type' => 'and',
                              'left' => 
                              array (
                                'type' => 'greater-equal',
                                'left' => 
                                array (
                                  'type' => 'variable',
                                  'value' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 740,
                                  'char' => 29,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 740,
                                  'char' => 34,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 740,
                                'char' => 34,
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
                                    'value' => 'text',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 740,
                                    'char' => 40,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'i',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 740,
                                    'char' => 42,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 740,
                                  'char' => 45,
                                ),
                                'right' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0x20',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 740,
                                  'char' => 53,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 740,
                                'char' => 53,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 740,
                              'char' => 53,
                            ),
                            'right' => 
                            array (
                              'type' => 'less-equal',
                              'left' => 
                              array (
                                'type' => 'variable',
                                'value' => 'paddingSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 740,
                                'char' => 67,
                              ),
                              'right' => 
                              array (
                                'type' => 'variable',
                                'value' => 'blockSize',
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 740,
                                'char' => 79,
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 740,
                              'char' => 79,
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 740,
                            'char' => 79,
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
                                  'assign-type' => 'incr',
                                  'variable' => 'paddingSize',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 741,
                                  'char' => 42,
                                ),
                                1 => 
                                array (
                                  'assign-type' => 'decr',
                                  'variable' => 'i',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 742,
                                  'char' => 32,
                                ),
                              ),
                              'file' => '/app/phalcon/Crypt.zep',
                              'line' => 743,
                              'char' => 21,
                            ),
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 745,
                          'char' => 25,
                        ),
                        2 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 747,
                          'char' => 23,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 747,
                      'char' => 23,
                    ),
                    6 => 
                    array (
                      'type' => 'default',
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'break',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 749,
                          'char' => 13,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 749,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 751,
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
                      'value' => 'paddingSize',
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 751,
                      'char' => 29,
                    ),
                    'right' => 
                    array (
                      'type' => 'less-equal',
                      'left' => 
                      array (
                        'type' => 'variable',
                        'value' => 'paddingSize',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 751,
                        'char' => 43,
                      ),
                      'right' => 
                      array (
                        'type' => 'variable',
                        'value' => 'blockSize',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 751,
                        'char' => 55,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 751,
                      'char' => 55,
                    ),
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 751,
                    'char' => 55,
                  ),
                  'statements' => 
                  array (
                    0 => 
                    array (
                      'type' => 'if',
                      'expr' => 
                      array (
                        'type' => 'less',
                        'left' => 
                        array (
                          'type' => 'variable',
                          'value' => 'paddingSize',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 752,
                          'char' => 32,
                        ),
                        'right' => 
                        array (
                          'type' => 'variable',
                          'value' => 'length',
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 752,
                          'char' => 41,
                        ),
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 752,
                        'char' => 41,
                      ),
                      'statements' => 
                      array (
                        0 => 
                        array (
                          'type' => 'return',
                          'expr' => 
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
                                  'value' => 'text',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 753,
                                  'char' => 39,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 753,
                                'char' => 39,
                              ),
                              1 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'int',
                                  'value' => '0',
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 753,
                                  'char' => 42,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 753,
                                'char' => 42,
                              ),
                              2 => 
                              array (
                                'parameter' => 
                                array (
                                  'type' => 'sub',
                                  'left' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'length',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 753,
                                    'char' => 51,
                                  ),
                                  'right' => 
                                  array (
                                    'type' => 'variable',
                                    'value' => 'paddingSize',
                                    'file' => '/app/phalcon/Crypt.zep',
                                    'line' => 753,
                                    'char' => 64,
                                  ),
                                  'file' => '/app/phalcon/Crypt.zep',
                                  'line' => 753,
                                  'char' => 64,
                                ),
                                'file' => '/app/phalcon/Crypt.zep',
                                'line' => 753,
                                'char' => 64,
                              ),
                            ),
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 753,
                            'char' => 65,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 754,
                          'char' => 17,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 756,
                      'char' => 22,
                    ),
                    1 => 
                    array (
                      'type' => 'return',
                      'expr' => 
                      array (
                        'type' => 'string',
                        'value' => '',
                        'file' => '/app/phalcon/Crypt.zep',
                        'line' => 756,
                        'char' => 24,
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 757,
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
                          'variable' => 'paddingSize',
                          'expr' => 
                          array (
                            'type' => 'int',
                            'value' => '0',
                            'file' => '/app/phalcon/Crypt.zep',
                            'line' => 758,
                            'char' => 36,
                          ),
                          'file' => '/app/phalcon/Crypt.zep',
                          'line' => 758,
                          'char' => 36,
                        ),
                      ),
                      'file' => '/app/phalcon/Crypt.zep',
                      'line' => 759,
                      'char' => 13,
                    ),
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 761,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 763,
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
                  'value' => 'paddingSize',
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 763,
                  'char' => 25,
                ),
                'file' => '/app/phalcon/Crypt.zep',
                'line' => 763,
                'char' => 25,
              ),
              'statements' => 
              array (
                0 => 
                array (
                  'type' => 'return',
                  'expr' => 
                  array (
                    'type' => 'variable',
                    'value' => 'text',
                    'file' => '/app/phalcon/Crypt.zep',
                    'line' => 764,
                    'char' => 24,
                  ),
                  'file' => '/app/phalcon/Crypt.zep',
                  'line' => 765,
                  'char' => 9,
                ),
              ),
              'file' => '/app/phalcon/Crypt.zep',
              'line' => 766,
              'char' => 5,
            ),
          ),
          'docblock' => '**
     * Removes a padding from a text.
     *
     * If the function detects that the text was not padded, it will return it
     * unmodified.
     *',
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 665,
          'last-line' => 767,
          'char' => 22,
        ),
      ),
      'constants' => 
      array (
        0 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_ANSI_X_923',
          'default' => 
          array (
            'type' => 'int',
            'value' => '1',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 37,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 38,
          'char' => 9,
        ),
        1 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_DEFAULT',
          'default' => 
          array (
            'type' => 'int',
            'value' => '0',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 38,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 39,
          'char' => 9,
        ),
        2 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_ISO_10126',
          'default' => 
          array (
            'type' => 'int',
            'value' => '3',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 39,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 40,
          'char' => 9,
        ),
        3 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_ISO_IEC_7816_4',
          'default' => 
          array (
            'type' => 'int',
            'value' => '4',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 40,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 41,
          'char' => 9,
        ),
        4 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_PKCS7',
          'default' => 
          array (
            'type' => 'int',
            'value' => '2',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 41,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 42,
          'char' => 9,
        ),
        5 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_SPACE',
          'default' => 
          array (
            'type' => 'int',
            'value' => '6',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 42,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 43,
          'char' => 9,
        ),
        6 => 
        array (
          'type' => 'const',
          'name' => 'PADDING_ZERO',
          'default' => 
          array (
            'type' => 'int',
            'value' => '5',
            'file' => '/app/phalcon/Crypt.zep',
            'line' => 43,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Crypt.zep',
          'line' => 47,
          'char' => 6,
        ),
      ),
      'file' => '/app/phalcon/Crypt.zep',
      'line' => 35,
      'char' => 5,
    ),
    'file' => '/app/phalcon/Crypt.zep',
    'line' => 35,
    'char' => 5,
  ),
);