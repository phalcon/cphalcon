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

use ArrayAccess;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Translate\Fake\FakeGettextFunctionExists;
use Phalcon\Tests\Unit\Translate\Fake\TranslateGettextTrait;
use Phalcon\Translate\Adapter\AdapterInterface;
use Phalcon\Translate\Adapter\Gettext;
use Phalcon\Translate\Exception;
use Phalcon\Translate\InterpolatorFactory;

final class ConstructTest extends AbstractUnitTestCase
{
    use TranslateGettextTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextConstruct(): void
    {

        $params     = $this->getGettextConfig();
        $translator = new Gettext(new InterpolatorFactory(), $params);

        $this->assertInstanceOf(ArrayAccess::class, $translator);
        $this->assertInstanceOf(AdapterInterface::class, $translator);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextConstructNoGettextException(): void
    {

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('This class requires the gettext extension for PHP');

        (new FakeGettextFunctionExists(
            new InterpolatorFactory(),
            ['locale' => 'en_US.utf8',]
        ));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextContentParamDirectoryExist(): void
    {

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Parameter 'directory' is required");

        (new Gettext(new InterpolatorFactory(), ['locale' => 'en_US.utf8',]));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testTranslateAdapterGettextContentParamLocaleExist(): void
    {

        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Parameter 'locale' is required");

        (new Gettext(new InterpolatorFactory(), []));
    }
}
