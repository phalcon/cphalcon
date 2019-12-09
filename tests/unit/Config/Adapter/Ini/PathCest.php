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

namespace Phalcon\Test\Unit\Config\Adapter\Ini;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterIniPath(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - path()');

        $this->checkPath($I, 'Ini');
    }

    /**
     * Tests Phalcon\Config\Adapter\Ini :: path() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterIniPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - path() - default');

        $this->checkPathDefault($I, 'Ini');
    }
}
