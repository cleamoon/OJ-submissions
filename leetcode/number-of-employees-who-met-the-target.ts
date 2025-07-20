function numberOfEmployeesWhoMetTarget(hours: number[], target: number): number {
    return hours.reduce((tot, h) => {
        if (h >= target) return tot + 1
        else return tot
    }, 0)
};