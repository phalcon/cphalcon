<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter;

use Phalcon\Translate\Adapter\Gettext;
use UnitTester;
use function dataDir;

class GettextCest
{
    /**
     * Executed before each test
     */
    public function _before(UnitTester $I)
    {
        $I->checkExtensionIsLoaded('gettext');

        if (!setlocale(LC_ALL, 'en_US.utf8')) {
            $I->skipTest("Locale en_US.utf8 not enabled");
        }
    }

    /**
     * Tests translator with array access
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-01-16
     */
    public function arrayAccess(UnitTester $I)
    {
        $I->wantTo("get access the translations by using array access");

        $translator = new Gettext(
            [
                'locale'        => 'en_US.utf8',
                'defaultDomain' => 'messages',
                'directory'     => dataDir('assets/translation/gettext'),
                'category'      => LC_MESSAGES,
            ]
        );

        $I->assertArrayHasKey('你好！', $translator);

        $I->assertArrayNotHasKey('Some non-existent string string', $translator);

        $I->assertEquals(
            'Hello!',
            $translator['你好！']
        );
    }

    /**
     * Tests the query Gettext::query
     *
     * @param  UnitTester $I
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-16
     */
    public function query(UnitTester $I)
    {
        $I->wantTo("translate by using Gettext::query");

        $translator = new Gettext(
            [
                'locale'        => 'en_US.utf8',
                'defaultDomain' => 'messages',
                'directory'     => dataDir('assets/translation/gettext'),
                'category'      => LC_MESSAGES,
            ]
        );

        $I->assertEquals(
            'Hello!',
            $translator->query('你好！')
        );

        $I->assertEquals(
            'Hello Phalcon!',
            $translator->query(
                '你好 %name%！',
                [
                    'name' => 'Phalcon',
                ]
            )
        );
    }

    /**
     * Tests variable substitution in string
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-16
     */
    public function substitution(UnitTester $I)
    {
        $I->wantTo("translate by using variable substitution in string");

        $translator = new Gettext(
            [
                'locale'        => 'en_US.utf8',
                'defaultDomain' => 'messages',
                'directory'     => dataDir('assets/translation/gettext'),
                'category'      => LC_MESSAGES,
            ]
        );

        $I->assertEquals(
            'Hello Phalcon!',
            $translator->t(
                '你好 %name%！',
                [
                    'name' => 'Phalcon',
                ]
            )
        );

        $I->assertEquals(
            'Hello Phalcon!',
            $translator->_(
                '你好 %name%！',
                [
                    'name' => 'Phalcon',
                ]
            )
        );
    }
}
