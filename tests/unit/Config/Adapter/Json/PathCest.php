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

namespace Phalcon\Test\Unit\Config\Adapter\Json;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class PathCest
{
    use ConfigTrait;

    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('json');
    }

    /**
     * Tests Phalcon\Config\Adapter\Json :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterJsonPath(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Json - path()');

        $this->checkPath($I, 'Json');
    }

    /**
     * Tests Phalcon\Config\Adapter\Json :: path() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterJsonPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Json - path() - default');

        $this->checkPathDefault($I, 'Json');
    }
}
