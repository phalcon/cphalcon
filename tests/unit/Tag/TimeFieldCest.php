<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Tag;

use Phalcon\Test\Fixtures\Helpers\TagHelper;

/**
 * Class TimeFieldCest
 *
 * @package Phalcon\Test\Unit\Tag
 */
class TimeFieldCest extends TagHelper
{
    protected $function  = 'timeField';
    protected $inputType = 'time';
}
