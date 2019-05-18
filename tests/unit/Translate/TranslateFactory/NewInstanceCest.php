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

namespace Phalcon\Test\Unit\Translate\TranslateFactory;

use UnitTester;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Translate\TranslateFactory :: newInstance()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-18
     */
    public function translateTranslateFactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Translate\TranslateFactory - newInstance()');

        $I->skipTest('Need implementation');
    }
}
