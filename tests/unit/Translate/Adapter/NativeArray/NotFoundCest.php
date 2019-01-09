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
use Phalcon\Test\Fixtures\Translate\Adapter\NativeAdapter;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use UnitTester;

/**
 * Class NotFoundCest
 */
class NotFoundCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFound(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound()');
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeArray(['content' => $language]);

        $expected = 'unknown';
        $actual   = $translator->query($expected);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - triggerError
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundTriggerError(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - triggerError');
        $I->expectThrowable(
            new Exception('Cannot find translation key: unknown'),
            function () {
                $language   = $this->getArrayConfig()['en'];
                $translator = new NativeArray(
                    [
                        'content'      => $language,
                        'triggerError' => true,
                    ]
                );
                $translator->query('unknown');
            }
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - triggerError random value
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundTriggerErrorRandomVaue(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - triggerError random value');
        $I->expectThrowable(
            new Exception('Cannot find translation key: unknown'),
            function () {
                $language   = $this->getArrayConfig()['en'];
                $translator = new NativeArray(
                    [
                        'content'      => $language,
                        'triggerError' => 'blahblah',
                    ]
                );
                $translator->query('unknown');
            }
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - custom
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundCustom(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - custom');
        $language   = $this->getArrayConfig()['en'];
        $translator = new NativeAdapter(['content' => $language]);

        $expected = '';
        $actual   = $translator->query('unknown');
        $I->assertEquals($expected, $actual);
    }
}
