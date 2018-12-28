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
use UnitTester;

/**
 * Class ExistsCest
 */
class ExistsCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: exists()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayExists(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - exists()');
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $actual = $translator->exists('hi');
        $I->assertTrue($actual);
    }
}
