<?php

namespace Phalcon\Test\Unit\Translate\Adapter;

use UnitTester;
use Phalcon\Translate\Adapter\Gettext;
use PHPUnit\Framework\SkippedTestError;

/**
 * \Phalcon\Test\Unit\Translate\Adapter\GettextCest
 * Tests the \Phalcon\Translate\Adapter\Gettext component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Translate\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class GettextCest
{
    /**
     * Executed before each test
     *
     * @param UnitTester $I
     */
    public function _before(UnitTester $I)
    {
        if (!extension_loaded('gettext')) {
            throw new SkippedTestError(
                'Warning: gettext extension is not loaded'
            );
        }

        if (!setlocale(LC_ALL, 'en_US.utf8')) {
            throw new SkippedTestError(
                "Locale en_US.utf8 not enabled"
            );
        }
    }

    /**
     * Tests translator with array access
     *
     * @param  UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-16
     */
    public function arrayAccess(UnitTester $I)
    {
        $I->wantTo("get access the translations by using array access");

        $translator = new Gettext(
            [
                'locale'        => 'en_US.utf8',
                'defaultDomain' => 'messages',
                'directory'     => PATH_DATA . 'translation/gettext',
                'category'      => LC_MESSAGES
            ]
        );

        $I->assertArrayHasKey('你好！', $translator);
        $I->assertArrayNotHasKey('Some non-existent string string', $translator);
        $I->assertEquals($translator['你好！'], 'Hello!');
    }

    /**
     * Tests whether a translation exists in db file
     *
     * @param  UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-01-16
     */
    public function exists(UnitTester $I)
    {
        $I->wantTo("check translation exists in db file by using Gettext::exists");

        $translator = new Gettext(
            [
                'locale'        => 'en_US.utf8',
                'defaultDomain' => 'messages',
                'directory'     => PATH_DATA . 'translation/gettext',
                'category'      => LC_MESSAGES
            ]
        );

        $I->assertFalse($translator->exists('更多的中国'));
        $I->assertFalse($translator->exists('Some non-existent string string'));
        $I->assertTrue($translator->exists('你好！'));
    }

    /**
     * Tests the query Gettext::query
     *
     * @param  UnitTester $I
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
                'directory'     => PATH_DATA . 'translation/gettext',
                'category'      => LC_MESSAGES
            ]
        );

        $I->assertEquals($translator->query('你好！'), 'Hello!');
        $I->assertEquals($translator->query('你好 %name%！', ['name' => 'Phalcon']), 'Hello Phalcon!');
    }

    /**
     * Tests variable substitution in string
     *
     * @param  UnitTester $I
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
                'directory'     => PATH_DATA . 'translation/gettext',
                'category'      => LC_MESSAGES
            ]
        );

        $I->assertEquals($translator->t('你好 %name%！', ['name' => 'Phalcon']), 'Hello Phalcon!');
        $I->assertEquals($translator->_('你好 %name%！', ['name' => 'Phalcon']), 'Hello Phalcon!');
    }
}
