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

namespace Phalcon\Test\Unit\Translate\Adapter\NativeArray;

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use UnitTester;

/**
 * Class OffsetSetCest
 */
class OffsetSetCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: offsetSet()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayOffsetSet(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - offsetSet() throws exception');
        $I->expectThrowable(
            new Exception('Translate is an immutable ArrayAccess object'),
            function () {
                $language   = $this->getArrayConfig()['en'];
                $translator = new NativeArray(['content' => $language]);
                $translator->offsetSet('team', 'Team');
            }
        );
    }
}
