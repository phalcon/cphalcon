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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

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
     * @since  2026-06-16
     */
    public function testHtmlBreadcrumbsRenderEmpty(): void
    {
        $breadcrumbs = new Breadcrumbs();

        $this->assertSame(
            '',
            $breadcrumbs->render()
        );
    }

    /**
     * The last label of a list of many elements goes into a `<dt>`, so it
     * must be escaped or a crafted label injects HTML (CWE-79).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testHtmlBreadcrumbsRenderEscapesLastLabel(): void
    {
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('Home', '/')
            ->add('<b>x</b>')
        ;

        $expected = '<dl>'
            . '<dt><a href="/">Home</a></dt>'
            . '<dt> / </dt>'
            . '<dt>&lt;b&gt;x&lt;/b&gt;</dt>'
            . '</dl>';

        $this->assertSame(
            $expected,
            $breadcrumbs->render()
        );
    }

    /**
     * The link and label are placed into the markup, so they must be escaped
     * or a crafted value injects HTML (CWE-79).
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function testHtmlBreadcrumbsRenderEscapesLinkAndLabel(): void
    {
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('<b>x</b>', '/a"><script>alert(1)</script>')
            ->add('Current')
        ;

        $actual = $breadcrumbs->render();

        $this->assertStringNotContainsString('<script>', $actual);
        $this->assertStringNotContainsString('<b>x</b>', $actual);
    }

    /**
     * A single element goes through the template branch, so the label and the
     * url must both be escaped or a crafted value injects HTML (CWE-79).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-25
     */
    public function testHtmlBreadcrumbsRenderEscapesSingleElement(): void
    {
        $breadcrumbs = new Breadcrumbs();
        $breadcrumbs
            ->add('<b>x</b>', '/a"><script>alert(1)</script>')
        ;

        $expected = '<dl>'
            . '<dt><a href="/a&quot;&gt;&lt;script&gt;alert(1)&lt;/script&gt;">'
            . '&lt;b&gt;x&lt;/b&gt;</a></dt>'
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
