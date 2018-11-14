<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Translate\Adapter\Gettext;

use Phalcon\Test\Fixtures\Traits\TranslateTrait;
use Phalcon\Translate\Adapter\Gettext;
use UnitTester;

class ExistsCest
{
    use TranslateTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: exists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testExists(UnitTester $I)
    {
        $params     = $this->getGettextConfig();
        $translator = new Gettext($params);

        $I->assertFalse($translator->exists('更多的中国'));
        $I->assertFalse($translator->exists('Some non-existent string string'));
        $I->assertTrue($translator->exists('你好！'));
    }
}
