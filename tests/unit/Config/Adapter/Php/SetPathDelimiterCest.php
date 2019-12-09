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

namespace Phalcon\Test\Unit\Config\Adapter\Php;

use Phalcon\Test\Fixtures\Traits\ConfigTrait;
use UnitTester;

class SetPathDelimiterCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Adapter\Php :: setPathDelimiter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function configAdapterPhpSetPathDelimiter(UnitTester $I)
    {
        $I->wantToTest('Config\Adapter\Php - setPathDelimiter()');
        $this->checkSetPathDelimiter($I, 'Php');
    }
}
