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

namespace Phalcon\Test\Unit\Config\Adapter\Ini;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

/**
 * Class PathCest
 */
class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: path()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
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
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configAdapterIniPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Ini - path() - default');
        $this->checkPathDefault($I, 'Ini');
    }
}
