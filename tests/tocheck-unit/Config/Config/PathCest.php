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

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: path()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configPath(UnitTester $I)
    {
        $I->wantToTest('Config - path()');

        $this->checkPath($I);
    }

    /**
     * Tests Phalcon\Config :: path() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config - path() - default');

        $this->checkPathDefault($I);
    }
}
