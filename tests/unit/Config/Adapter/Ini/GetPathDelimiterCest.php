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

class GetPathDelimiterCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Ini :: getPathDelimiter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterIniGetPathDelimiter(UnitTester $I)
    {
        $I->wantToTest("Config\Adapter\Ini - getPathDelimiter()");
        $this->checkGetPathDelimiter($I, 'Ini');
    }
}
