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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextTrait;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\InterpolatorFactory;

final class NqueryTest extends AbstractUnitTestCase
{
    use TranslateGettextTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextNquery(): void
    {

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $expected = 'two files';
        $actual   = $translator->nquery('file', 'files', 2);
        $this->assertSame($expected, $actual);

        $expected = 'two files';
        $actual   = $translator->nquery('file', 'files', 2, [], 'messages');
        $this->assertSame($expected, $actual);
    }
}
