<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

class GossipRobots extends Model
{
    public $trace = [];

    public function initialize()
    {
        $this->setSource('robots');
    }

    public function beforeValidation()
    {
        $this->_talk(__METHOD__);
    }

    protected function _talk(string $completeMethod)
    {
        $class  = get_class($this);
        $method = explode('::', $completeMethod);

        if (!isset($this->trace[$method[1]][$class])) {
            $this->trace[$method[1]][$class] = 0;
        }

        $this->trace[$method[1]][$class]++;
    }

    public function beforeValidationOnUpdate()
    {
        $this->_talk(__METHOD__);
    }

    public function afterValidationOnUpdate()
    {
        $this->_talk(__METHOD__);
    }

    public function validation()
    {
        $this->_talk(__METHOD__);
    }

    public function afterValidation()
    {
        $this->_talk(__METHOD__);
    }

    public function beforeSave()
    {
        $this->_talk(__METHOD__);
    }

    public function beforeUpdate()
    {
        $this->_talk(__METHOD__);
    }

    public function afterUpdate()
    {
        $this->_talk(__METHOD__);
    }

    public function afterSave()
    {
        $this->_talk(__METHOD__);
    }

    public function beforeCreate()
    {
        $this->_talk(__METHOD__);

        return false;
    }

    public function beforeDelete()
    {
        $this->_talk(__METHOD__);

        return false;
    }

    public function notSaved()
    {
        $this->_talk(__METHOD__);

        return false;
    }
}
