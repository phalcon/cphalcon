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

namespace Phalcon\Tests\Unit\Config\Config;

use Phalcon\Tests\Fixtures\Traits\ConfigTrait;
use UnitTester;

class SetPathDelimiterCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config\Config :: setPathDelimiter()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-06-19
     */
    public function configSetPathDelimiter(UnitTester $I)
    {
        $I->wantToTest('Config - setPathDelimiter()');

        $this->checkSetPathDelimiter($I);
    }
}
