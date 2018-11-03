<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Phalcon\Test\Models\People
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class People extends Model
{
    public $cedula;
    public $tipo_documento_id;
    public $nombres;
    public $telefono;
    public $direccion;
    public $email;
    public $fecha_nacimiento;
    public $ciudad_id;
    public $cupo;
    public $estado;
    public $creado_at;

    public function getSource()
    {
        return 'personas';
    }
}
