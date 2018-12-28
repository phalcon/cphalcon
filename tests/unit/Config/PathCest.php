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

namespace Phalcon\Test\Unit\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

/**
 * Class PathCest
 */
class PathCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: path()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configPath(UnitTester $I)
    {
        $I->wantToTest('Config - path()');
        $this->checkPath($I);
    }

    /**
     * Tests Phalcon\Config :: path() - default
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function configPathDefault(UnitTester $I)
    {
        $I->wantToTest('Config - path() - default');
        $this->checkPathDefault($I);
    }
}
