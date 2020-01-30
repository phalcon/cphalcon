<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use UnitTester;

trait SessionBagTrait
{
    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();
    }

    abstract protected function setNewFactoryDefault();

    abstract protected function setDiSessionFiles();
}
