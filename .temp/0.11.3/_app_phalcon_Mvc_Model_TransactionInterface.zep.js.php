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
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
    'line' => 11,
    'char' => 9,
  ),
  1 => 
  array (
    'type' => 'namespace',
    'name' => 'Phalcon\\Mvc\\Model',
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\ModelInterface',
        'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
        'line' => 13,
        'char' => 31,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
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
        'name' => 'Phalcon\\Mvc\\Model\\Transaction\\ManagerInterface',
        'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
        'line' => 14,
        'char' => 51,
      ),
    ),
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
    'line' => 20,
    'char' => 2,
  ),
  4 => 
  array (
    'type' => 'comment',
    'value' => '**
 * Phalcon\\Mvc\\Model\\TransactionInterface
 *
 * Interface for Phalcon\\Mvc\\Model\\Transaction
 *',
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
    'line' => 21,
    'char' => 9,
  ),
  5 => 
  array (
    'type' => 'interface',
    'name' => 'TransactionInterface',
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
          'name' => 'begin',
          'docblock' => '**
     * Starts the transaction
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 26,
                'char' => 36,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 26,
            'char' => 36,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 26,
          'last-line' => 30,
          'char' => 19,
        ),
        1 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'commit',
          'docblock' => '**
     * Commits the transaction
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 31,
                'char' => 37,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 31,
            'char' => 37,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 31,
          'last-line' => 35,
          'char' => 19,
        ),
        2 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getConnection',
          'docblock' => '**
     * Returns connection related to transaction
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
                  'value' => '\\Phalcon\\Db\\AdapterInterface',
                  'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                  'line' => 36,
                  'char' => 70,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 36,
                'char' => 70,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 36,
            'char' => 70,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 36,
          'last-line' => 40,
          'char' => 19,
        ),
        3 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'getMessages',
          'docblock' => '**
     * Returns validations messages from last save try
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 41,
                'char' => 43,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 41,
            'char' => 43,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 41,
          'last-line' => 45,
          'char' => 19,
        ),
        4 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isManaged',
          'docblock' => '**
     * Checks whether transaction is managed by a transaction manager
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 46,
                'char' => 40,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 46,
            'char' => 40,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 46,
          'last-line' => 50,
          'char' => 19,
        ),
        5 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'isValid',
          'docblock' => '**
     * Checks whether internal connection is under an active transaction
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 51,
                'char' => 38,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 51,
            'char' => 38,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 51,
          'last-line' => 55,
          'char' => 19,
        ),
        6 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'rollback',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackMessage',
              'const' => 0,
              'data-type' => 'string',
              'mandatory' => 0,
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 56,
                'char' => 59,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 56,
              'char' => 59,
            ),
            1 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackRecord',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 56,
                'char' => 91,
              ),
              'default' => 
              array (
                'type' => 'null',
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 56,
                'char' => 99,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 56,
              'char' => 99,
            ),
          ),
          'docblock' => '**
     * Rollbacks the transaction
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
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 56,
                'char' => 108,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 56,
            'char' => 108,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 56,
          'last-line' => 60,
          'char' => 19,
        ),
        7 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setIsNewTransaction',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'isNew',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 61,
              'char' => 51,
            ),
          ),
          'docblock' => '**
     * Sets if is a reused transaction or new once
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 61,
            'char' => 60,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 61,
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
          'name' => 'setRollbackOnAbort',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'rollbackOnAbort',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 66,
              'char' => 60,
            ),
          ),
          'docblock' => '**
     * Sets flag to rollback on abort the HTTP connection
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 66,
            'char' => 69,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 66,
          'last-line' => 70,
          'char' => 19,
        ),
        9 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setRollbackedRecord',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'record',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ModelInterface',
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 71,
                'char' => 63,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 71,
              'char' => 64,
            ),
          ),
          'docblock' => '**
     * Sets object which generates rollback action
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 71,
            'char' => 73,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 71,
          'last-line' => 75,
          'char' => 19,
        ),
        10 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'setTransactionManager',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'manager',
              'const' => 0,
              'data-type' => 'variable',
              'mandatory' => 0,
              'cast' => 
              array (
                'type' => 'variable',
                'value' => 'ManagerInterface',
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 76,
                'char' => 68,
              ),
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 76,
              'char' => 69,
            ),
          ),
          'docblock' => '**
     * Sets transaction manager related to the transaction
     *',
          'return-type' => 
          array (
            'type' => 'return-type',
            'void' => 1,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 76,
            'char' => 78,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 76,
          'last-line' => 80,
          'char' => 19,
        ),
        11 => 
        array (
          'visibility' => 
          array (
            0 => 'public',
          ),
          'type' => 'method',
          'name' => 'throwRollbackException',
          'parameters' => 
          array (
            0 => 
            array (
              'type' => 'parameter',
              'name' => 'status',
              'const' => 0,
              'data-type' => 'bool',
              'mandatory' => 0,
              'reference' => 0,
              'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
              'line' => 81,
              'char' => 55,
            ),
          ),
          'docblock' => '**
     * Enables throwing exception
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
                  'value' => 'TransactionInterface',
                  'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                  'line' => 81,
                  'char' => 82,
                ),
                'collection' => 0,
                'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
                'line' => 81,
                'char' => 82,
              ),
            ),
            'void' => 0,
            'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
            'line' => 81,
            'char' => 82,
          ),
          'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
          'line' => 81,
          'last-line' => 82,
          'char' => 19,
        ),
      ),
      'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
      'line' => 82,
      'char' => 1,
    ),
    'file' => '/app/phalcon/Mvc/Model/TransactionInterface.zep',
    'line' => 0,
    'char' => 0,
  ),
);