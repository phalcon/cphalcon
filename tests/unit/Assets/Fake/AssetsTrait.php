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

namespace Phalcon\Tests\Unit\Assets\Fake;

trait AssetsTrait
{
    /**
     * @return string[][]
     */
    public static function providerAssets(): array
    {
        return [
            [
                'css',
                'assets/assets/1198.css',
            ],
            [
                'js',
                'assets/assets/jquery.js',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerCss(): array
    {
        return [
            [
                'css/docs.css',
                true,
            ],
            [
                'https://phalcon.ld/css/docs.css',
                false,
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerCssIsLocal(): array
    {
        return [
            [
                'css/docs.css',
                true,
                false,
            ],
            [
                'https://phalcon.ld/css/docs.css',
                false,
                true,
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function providerCssJs(): array
    {
        return [
            [
                'css',
                'assets/assets/1198.css',
            ],
            [
                'js',
                'assets/assets/signup.js',
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function providerCssJsLocal(): array
    {
        return [
            [
                'css',
                'css/docs.css',
                true,
            ],
            [
                'js',
                'js/jquery.js',
                true,
            ],
            [
                'css',
                'https://phalcon.ld/css/docs.css',
                false,
            ],
            [
                'js',
                'https://phalcon.ld/js/jquery.js',
                false,
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function providerCssJsTargetUri(): array
    {
        return [
            [
                'css',
                'css/docs.css',
                true,
                '',
                'css/docs.css',
            ],
            [
                'js',
                'js/jquery.js',
                true,
                '',
                'js/jquery.js',
            ],
            [
                'css',
                'https://phalcon.ld/css/docs.css',
                false,
                '',
                'https://phalcon.ld/css/docs.css',
            ],
            [
                'js',
                'https://phalcon.ld/js/jquery.js',
                false,
                '',
                'https://phalcon.ld/js/jquery.js',
            ],
            [
                'css',
                'css/assets.css',
                true,
                'css/docs.css',
                'css/docs.css',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerInlineCssJs(): array
    {
        return [
            [
                'css',
                'p {color: #000099}',
            ],
            [
                'js',
                '<script>alert("Hello");</script>',
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function providerInlineCssJsType(): array
    {
        return [
            [
                'css',
                'p {color: #000099}',
                'js',
            ],
            [
                'js',
                '<script>alert("Hello");</script>',
                'css',
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerJs(): array
    {
        return [
            [
                'js/jquery.js',
                true,
            ],
            [
                'https://phalcon.ld/js/jquery.js',
                false,
            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerJsIsLocal(): array
    {
        return [
            [
                'js/jquery.js',
                true,
                false,
            ],
            [
                'https://phalcon.ld/js/jquery.js',
                false,
                true,
            ],
        ];
    }
}
