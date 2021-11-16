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

namespace Phalcon\Tests\Unit\Translate\Adapter\Gettext;

use Phalcon\Tests\Fixtures\Traits\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;
use UnitTester;

use function dataDir;

/**
 * Class GetSetDirectoryCest
 *
 * @package Phalcon\Tests\Unit\Translate\Adapter\Gettext
 */
class GetSetDirectoryCest
{
    use TranslateGettextTrait;

    /**
     * Tests Phalcon\Translate\Adapter\Gettext :: getDirectory()/setDirectory()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function translateAdapterGettextGetSetDirectory(UnitTester $I)
    {
        $I->wantToTest('Translate\Adapter\Gettext - getDirectory()/setDirectory()');

        $params = $this->getGettextConfig();

        $translator = new Gettext(new InterpolatorFactory(), $params);

        $expected = dataDir('assets/translation/gettext');
        $actual   = $translator->getDirectory();
        $I->assertEquals($expected, $actual);

        $translator->setDirectory(dataDir());

        $expected = dataDir();
        $actual   = $translator->getDirectory();
        $I->assertEquals($expected, $actual);
    }
}
