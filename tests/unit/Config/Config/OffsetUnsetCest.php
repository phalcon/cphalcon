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

class OffsetUnsetCest
{
    use ConfigTrait;

    /**
     * Tests Phalcon\Config :: offsetUnset()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-06-19
     */
    public function configOffsetUnset(UnitTester $I)
    {
        $I->wantToTest('Config - offsetUnset()');
        $this->checkOffsetUnset($I);
    }
}
