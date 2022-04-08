#pragma once

/// <summary>
/// Interface for all shapes. All shapes to be displayed
/// should be inherited from this class
/// </summary>
class IShape {
 public:
    /// <summary>
    /// Outputs information about shape to console
    /// </summary>
    virtual void print_info() const = 0;

    /// <summary>
    /// Virtual destructor, provides correct destruction of
    /// inherited classes
    /// </summary>
    virtual ~IShape();
};
