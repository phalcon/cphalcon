<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Fixtures\Tasks;

class ParamsTask extends \Phalcon\Cli\Task
{
    public function paramsAction()
    {
        return (func_get_args() === $this->dispatcher->getParams())
            ? 'Action params are the same as $this->dispatcher->getParams()'
            : 'Action params are not the same as $this->dispatcher->getParams()';
    }

    public function paramAction($param)
    {
        return ($param === $this->dispatcher->getParam(0))
            ? '$param[0] is the same as $this->dispatcher->getParam(0)'
            : '$param[0] is not the same as $this->dispatcher->getParam(0)';
    }
}
