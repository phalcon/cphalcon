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

namespace Phalcon\Test\Unit\Translate\Adapter\NativeArray;

use Phalcon\Test\Fixtures\Traits\TranslateArrayTrait;
use Phalcon\Test\Fixtures\Translate\Adapter\NativeAdapter;
use Phalcon\Translate\Adapter\NativeArray;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

class NotFoundCest
{
    use TranslateArrayTrait;

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - default
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFound(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound()');

        $language = $this->getArrayConfig()['en'];

        $translator = new NativeArray(
            new InterpolatorFactory(),
            [
                'content' => $language,
            ]
        );

        $expected = 'unknown';

        $I->assertEquals(
            $expected,
            $translator->query($expected)
        );
    }

    /**
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - triggerError
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundTriggerError(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - triggerError');

        $I->expectThrowable(
            new Exception('Cannot find translation key: unknown'),
            function () {
                $language = $this->getArrayConfig()['en'];

                $translator = new NativeArray(
                    new InterpolatorFactory(),
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
     * Tests Phalcon\Translate\Adapter\NativeArray :: notFound() - triggerError
     * random value
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundTriggerErrorRandomVaue(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - triggerError random value');

        $I->expectThrowable(
            new Exception('Cannot find translation key: unknown'),
            function () {
                $language = $this->getArrayConfig()['en'];

                $translator = new NativeArray(
                    new InterpolatorFactory(),
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function translateAdapterNativearrayNotFoundCustom(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\NativeArray - notFound() - custom');

        $language = $this->getArrayConfig()['en'];

        $translator = new NativeAdapter(
            new InterpolatorFactory(),
            [
                'content' => $language,
            ]
        );

        $I->assertEquals(
            '',
            $translator->query('unknown')
        );
    }
}
