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

namespace Phalcon\Test\Unit\Config\Config;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class SetPathDelimiterCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: setPathDelimiter()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-19
     */
    public function configSetPathDelimiter(UnitTester $I)
    {
        $I->wantToTest('Config - setPathDelimiter()');
        $this->checkSetPathDelimiter($I);
    }
}
