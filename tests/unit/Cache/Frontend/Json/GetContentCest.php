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

namespace Phalcon\Test\Unit\Cache\Frontend\Json;

use UnitTester;

/**
 * Class GetContentCest
 */
class GetContentCest
{
    /**
     * Tests Phalcon\Cache\Frontend\Json :: getContent()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheFrontendJsonGetContent(UnitTester $I)
    {
        $I->wantToTest('Cache\Frontend\Json - getContent()');
        $I->skipTest('Need implementation');
    }
}
