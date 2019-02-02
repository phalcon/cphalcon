<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use UnitTester;

/**
 * Trait SessionBagTrait
 *
 * @package Phalcon\Test\Fixtures\Traits
 */
trait SessionBagTrait
{
    /**
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiSessionFiles();
    }

    /**
     * @return mixed
     */
    abstract protected function setNewFactoryDefault();

    /**
     * @return mixed
     */
    abstract protected function setDiSessionFiles();
}
