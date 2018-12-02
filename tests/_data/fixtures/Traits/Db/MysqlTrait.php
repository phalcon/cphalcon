<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits\Db;

trait MysqlTrait
{
    protected $connection = null;

    public function _before()
    {
        $this->newFactoryDefault();
        $this->setDiMysql();

        $this->connection = $this->getService('db');
    }

    abstract protected function newFactoryDefault();

    abstract protected function setDiMysql();
}
