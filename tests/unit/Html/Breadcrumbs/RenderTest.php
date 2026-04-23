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

namespace Phalcon\Tests\Unit\Html\Breadcrumbs;

use Phalcon\Html\Breadcrumbs;
use Phalcon\Tests\AbstractUnitTestCase;

final class RenderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlBreadcrumbsRender(): void
    {
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('Home', '/')
            ->add('Phalcon Team')
        ;

        $expected = '<dl>'
            . '<dt><a href="/">Home</a></dt>'
            . '<dt> / </dt>'
            . '<dt>Phalcon Team</dt>'
            . '</dl>';

        $this->assertSame(
            $expected,
            $breadcrumbs->render()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testHtmlBreadcrumbsRenderHome(): void
    {
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('Home', '/')
        ;

        $expected = '<dl>'
            . '<dt><a href="/">Home</a></dt>'
            . '</dl>';

        $this->assertSame(
            $expected,
            $breadcrumbs->render()
        );
    }
}
